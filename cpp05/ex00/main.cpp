# include "Bureaucrat.hpp"

int main()
{
	try { std::cout << Bureaucrat("Jack", 1) << std::endl; }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	try { std::cout << Bureaucrat("Nick", 0) << std::endl; }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	try { std::cout << Bureaucrat("Alice", 151) << std::endl; }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }
}