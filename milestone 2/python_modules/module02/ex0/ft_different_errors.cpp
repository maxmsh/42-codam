#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <exception>

void	garden_operations(void)
{
	int	input, error_types = 0;
	std::string filename;

	try
	{
		std::cout << "What type of errors would you like to test? 1 = int, 2 = string: ";
		std::cin >> error_types;
		if (error_types == 1) // By default, the error type to test is integer input -- which corresponds to 0
		{
			std::cout << "\n" << "Please enter integer input: " << std::endl; // User is prompted to give integer input
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
		else
		{
			std::cout << "Your input of " << input << " was valid!" << std::endl;
		}
		}
		else if (error_types == 2)
		{
			std::cout << "\n" << "Please enter a valid filename: " << std::endl;
			std::cin >> filename;
			std::cout << "No. Fuck you. " << std::endl;

		}
		else if (error_types != 1 && error_types != 2)
		{
			std::cout << "No valid error type was specified." << std::endl;
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
