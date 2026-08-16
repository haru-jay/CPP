#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::~PmergeMe()
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
	{
		_vector = rhs._vector;
		_list = rhs._list;
	}
	return *this;
}

PmergeMe::PmergeMe(const PmergeMe& rhs)
{
	_vector = rhs._vector;
	_list = rhs._list;
}

void PmergeMe::run(int argc, char** argv)
{
	if(argc < 2)
		throw std::runtime_error("Error");
	for(int i = 1; i < argc; ++i)
	{
		char *endptr;
		long long value = std::strtoll(argv[i], &endptr, 10);
		
		if(endptr == argv[i] || *endptr != '\0')
			throw std::runtime_error("Error");
		if(value <= 0 || value > INT_MAX)
			throw std::runtime_error("Error");
		_vector.push_back(static_cast<int>(value));
		_list.push_back(static_cast<int>(value));
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
	struct timeval start, end;

	gettimeofday(&start, NULL);
	mergeInsertSortVector(_vector);
	gettimeofday(&end, NULL);
	double vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	gettimeofday(&start, NULL);
	mergeInsertSortList(_list);
	gettimeofday(&end, NULL);
	double listTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	std::cout << "After: ";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _vector.size()
			  << " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _list.size()
			  << " elements with std::list : " << listTime << " us" << std::endl;
}

void PmergeMe::mergeInsertSortVector(std::vector<int> &v)
{
	if (v.size() <= 1)
		return;
	std::vector<int> bigger;
	std::vector<int> smaller;
	bool hasOdd = (v.size() % 2 != 0);
	int odd = hasOdd ? v.back() : 0;

	for (size_t i = 0; i + 1 < v.size(); i += 2)
	{
		if (v[i] > v[i + 1])
		{
			bigger.push_back(v[i]);
			smaller.push_back(v[i + 1]);
		}
		else
		{
			bigger.push_back(v[i + 1]);
			smaller.push_back(v[i]);
		}
	}
	mergeInsertSortVector(bigger);
	std::vector<size_t> vecOrder = buildInsertionOrder(smaller.size());
	for (size_t k = 0; k < vecOrder.size(); ++k)
	{
		int val = smaller[vecOrder[k]];
		std::vector<int>::iterator pos = std::upper_bound(bigger.begin(), bigger.end(), val);
		bigger.insert(pos, val);
	}
	if (hasOdd)
	{
		std::vector<int>::iterator pos = std::upper_bound(bigger.begin(), bigger.end(), odd);
		bigger.insert(pos, odd);
	}
	v = bigger;
}

void PmergeMe::mergeInsertSortList(std::list<int> &v)
{
	if (v.size() <= 1)
		return;

	std::list<int> bigger;
	std::list<int> smaller;
	bool hasOdd = (v.size() % 2 != 0);
	int odd = hasOdd ? v.back() : 0;

	std::list<int>::iterator it = v.begin();
	std::list<int>::iterator end = v.end();
	if (hasOdd)
		--end;
	while (it != end)
	{
		int first = *it;
		++it;
		int second = *it;
		++it;

		if (first > second)
		{
			bigger.push_back(first);
			smaller.push_back(second);
		}
		else
		{
			bigger.push_back(second);
			smaller.push_back(first);
		}
	}
	mergeInsertSortList(bigger);
	std::vector<int> smallerVec(smaller.begin(), smaller.end());
	std::vector<size_t> listOrder = buildInsertionOrder(smallerVec.size());
	for (size_t k = 0; k < listOrder.size(); ++k)
	{
		int val = smallerVec[listOrder[k]];
		std::list<int>::iterator pos = std::upper_bound(bigger.begin(), bigger.end(), val);
		bigger.insert(pos, val);
	}
	if (hasOdd)
	{
		std::list<int>::iterator pos = std::upper_bound(bigger.begin(), bigger.end(), odd);
		bigger.insert(pos, odd);
	}
	v = bigger;
}

std::vector<size_t> PmergeMe::buildInsertionOrder(size_t n)
{
	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	while (jacobsthal.back() < n)
		jacobsthal.push_back(jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2]);

	std::vector<size_t> order;
	for (size_t k = 1; k < jacobsthal.size(); ++k)
	{
		size_t lo = jacobsthal[k - 1];
		size_t hi = jacobsthal[k];
		if (hi > n)
			hi = n;
		for (size_t idx = hi; idx > lo; --idx)
			order.push_back(idx - 1);
	}
	return order;
}