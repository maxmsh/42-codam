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
		std::cout << "Please enter input: " << std::endl;
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cout << "Testing ValueError..." << std::endl;
			throw std::invalid_argument("Caught ValueError: invalid literal for int()");
			std::cin.ignore(10000, '\n');
			std::cin.clear();
		}
		else if (input == 0)
		{
			std::cout << "Testing ZeroDivisionError..." << std::endl;
			throw std::runtime_error("Caught ZeroDivisionError: division by zero");
			std::cin.ignore(10000, '\n');
			std::cin.clear();
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

	try
	{
		std::cout << "Please specify a filename: " << std::endl;
		std::cin >> filename;

		if (!filename.open())
		{
			throw 
		}
	}
	catch
	{

	}
}

int	main(void)
{
	std::cout << "=== Garden Error Types Demo ==="
				<< "\n\n";
	garden_operations();
}