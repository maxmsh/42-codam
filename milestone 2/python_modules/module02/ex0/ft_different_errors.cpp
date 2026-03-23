#include <iostream>
#include <exception>
#include <fstream>
#include <stdexcept>
#include <string>

void	garden_operations(void)
{
	std::string error_types, choose, second_choice, second_bin;
	int input, second_input, num, divisor, result;
	std::string filename;

	try
	{
		std::cout << "Would you like to test int or string errors? ";
		std::cin >> error_types;
		if ((error_types == "int") || (error_types == "int errors"))
		{
			std::cout << "Would you like to test value errors or division errors? " << std::endl;
			std::cin >> choose;
			if ((choose == "value") || (choose == "Value") || (choose == "value errors") || (choose == "Value errors") || (choose == "Value Errors"))
			{
				std::cout << "\n" << "Please enter valid integer input: " << std::endl;
				std::cin >> input;
				if (std::cin.fail())
				{
					std::cout << "Testing ValueError..." << std::endl;
					throw std::invalid_argument("Caught ValueError: invalid literal for int()");
				}
				else
				{
					std::cout << "Your integer value of " << input << " was accepted!" << std::endl;
				}
			}
			else if (choose == "division" || choose == "division errors" || choose == "Division" || choose == "Division Errors")
			{
				std::cout << "Please enter the first of two number inputs to perform a division: " << std::endl;
				std::cin >> num;
				if (std::cin.fail() || std::cin.peek() != '\n' || num == 0)
				{
					std::cout << "Testing ValueError..." << std::endl;
					throw std::invalid_argument("Caught ValueError: invalid literal for int()");
				}
				else
				{
					std::cout << "First number of " << num << " selected. Now enter a second value: " << std::endl;
					std::cin >> divisor;
					if (std::cin.peek() != '\n')
					{
						std::cout << "Testing ValueError..." << std::endl;
						throw std::invalid_argument("Caught ValueError: invalid literal for int()");
					}
					else if (divisor == 0)
					{
						std::cout << "Testing ZeroDivisionError..." << std::endl;
						throw std::runtime_error("Caught ZeroDivisionError: division by zero");
					}
					else
					{
						result = num / divisor;
						std::cout << num << " divided by " << divisor << " is: " << result << std::endl;
					}
				}
			}
		}
		else if ((error_types == "errors") || (error_types == "Errors"))
		{
			std::cout << "Please specify. Would you like to test int or string error types?" << std::endl;
			std::cin >> second_choice;
			if ((second_choice == "int") || (second_choice == "int errors"))
			{
				std::cout << "Would you like to value or division errors?" << std::endl;
				std::cin >> second_bin;
				if ((second_bin == "value" || second_bin == "value errors"))
				{
					std::cout << "\n" << "Please enter valid integer input: " << std::endl;
					std::cin >> second_input;
					if (std::cin.fail())
					{
						std::cout << "Testing ValueError... " << std::endl;
						throw std::invalid_argument("Caught ValueError: invalid literal for int()");
					}
					else
					{
						std::cout << "Your integer value of " << second_input << " was accepted!" << std::endl;
					}
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
	catch (const std::invalid_argument &e)
	{
		std::cerr << e.what() << '\n';
	}
	catch (const std::runtime_error &e)
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
