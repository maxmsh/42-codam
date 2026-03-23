#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>

void	garden_operations(int num, int divisor, std::string filename)
{
	try
	{
		if (!std::isdigit(num))
		{
			throw std::invalid_argument("");
		}
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "Testing ValueError..." << "\n";
		std::cout << "Caught ValueError: invalid literal for int()" << std::endl;
	}
	try
	{
		if (num == 0 || divisor == 0)
		{
			throw std::logic_error("");
		}
	}
	catch (const std::logic_error &e)
	{
		std::cout << "Testing ZeroDivisionError..." << "\n";
		std::cout << "Caught ZeroDivisionError: division by zero" << std::endl;
	}
}

int	main(void)
{
	std::cout << "=== Garden Error Types Demo ==="
				<< "\n\n";
	garden_operations('i', 0, "missing.txt");
}
