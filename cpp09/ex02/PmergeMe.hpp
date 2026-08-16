#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <climits>

class PmergeMe
{
private:
	std::vector<int> _vector;
	std::list<int> _list;

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& rhs);
	PmergeMe& operator=(const PmergeMe& rhs);
	void run(int argc, char** argv);
	void mergeInsertSortVector(std::vector<int> &v);
	void mergeInsertSortList(std::list<int> &v);
	std::vector<size_t> buildInsertionOrder(size_t n);
};




#endif