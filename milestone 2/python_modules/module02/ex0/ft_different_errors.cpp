#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <exception>

void	garden_operations(void)
{
	std::string error_types, choose;
	int	input = 0;
	float num, divisor;
	std::string filename;

	try
	{
		std::cout << "Would you like to test int or string errors? ";
		std::cin >> error_types;
		if ((error_types == "int") || (error_types == "int errors")) // By default, the error type to test is integer input -- which corresponds to 0
		{
			std::cout << "Would you like to test value errors or division errors? ";
			std::cin >> choose;
			if ((choose == "value") || (choose == "value errors"))
			{
			std::cout << "\n" << "Please enter valid integer input: " << std::endl; // User is prompted to give integer input
			std::cin >> input;
		if (std::cin.fail())
		{
			std::cout << "Testing ValueError..." << std::endl;
			throw std::invalid_argument("Caught ValueError: invalid literal for int()"); // If the value the user has put in is invalid, then they will see a TypeError message
		}
		else
		{
			std::cout << "Your integer value of " << input << "was accepted!" << std::endl;
		}
		}
		else if ((choose == "division") || (choose == "division errors"))
		{
			std::cout << "Please enter the first of two number inputs to perform a division: " << std::endl;
			std::cin >> num;
			std::cout << "First number of " << num << " selected. Now enter a second value: " << std::endl;
			std::cin >> divisor;
			if ((num == 0) || (divisor == 0))
			{
				std::cout << "Testing ZeroDivisionError..." << std::endl;
				throw std::runtime_error("Caught ZeroDivisionError: division by zero");
			}
			else
			{
				std::cout << "Number values of " << num << " and " << divisor << " are valid to make a division!" << std::endl;
			}
		}
		}
		else if ((error_types == "string") || (error_types == "string errors"))
		{
			std::cout << "\n" << "Please enter a valid filename: " << std::endl;
			std::cin >> filename;
			std::cout << "No. Fuck you. " << std::endl;

		}
		else if (error_types != "int" && error_types != "int errors" && error_types != "string" && error_types != "string errors")
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
