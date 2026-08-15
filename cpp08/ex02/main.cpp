#include "MutantStack.hpp"
#include <string>

void printStack(const MutantStack<int> &s)
{
	for (MutantStack<int>::const_iterator it = s.begin(); it != s.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	MutantStack<int> emptyStack;
	std::cout << "empty stack begin==end: " << (emptyStack.begin() == emptyStack.end()) << std::endl;

	MutantStack<int> original;
	original.push(1);
	original.push(2);
	MutantStack<int> copy(original);
	copy.push(999);
	std::cout << "original size: " << original.size() << ", copy size: " << copy.size() << std::endl;

	MutantStack<int> assigned;
	assigned = original;
	assigned.push(42);
	std::cout << "original size: " << original.size() << ", assigned size: " << assigned.size() << std::endl;

	MutantStack<std::string> sstack;
	sstack.push("hello");
	sstack.push("world");
	for (MutantStack<std::string>::iterator sit = sstack.begin(); sit != sstack.end(); ++sit)
		std::cout << *sit << " ";
	std::cout << std::endl;

	printStack(mstack);

	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;

	return 0;
}
