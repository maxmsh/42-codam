#include <iostream>
#include <stdexcept>
#include <string>
#include <exception>

void	garden_operations(void)
{
	int	input;
	std::string filename;

	try
	{
		input = 0;
		std::cout << "Please enter input: " << std::endl; // User is prompted to give input
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cout << "Testing ValueError..." << std::endl;
			throw std::invalid_argument("Caught ValueError: invalid literal for int()"); // If the value the user has put in is invalid, then they will see a TypeError message
			std::cin.ignore(10, '\n');
			std::cin.clear();
			std::cout << "Try again, please. " << std::endl;
			std::cin >> input;
		}
		else if (input == 0)
		{
			std::cout << "Testing ZeroDivisionError..." << std::endl;
			throw std::runtime_error("Caught ZeroDivisionError: division by zero"); // This is mainly used for testing purposes, but division by 0 should not be possible
			std::cin.ignore(10000, '\n');
			std::cin.clear();
			std::cout << "Try again, please. " << std::endl;
			std::cin >> input;
		}
	}
	catch(const std::invalid_argument &e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const std::runtime_error &e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(void)
{
	std::cout << "=== Garden Error Types Demo ==="
				<< "\n\n";
	garden_operations();
}
