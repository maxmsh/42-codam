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
			throw std::invalid_argument("Testing ValueError...\n");
		}
		else if (num / divisor == 0)
		{
			throw std::logic_error("Testing ZeroDivisionError...\n");
		}
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "Testing ValueError..." << std::endl;
		std::cout << "Caught ValueError: invalid literal for int()" << std::endl;
	}
	catch (const std::logic_error &e)
	{
		std::cout << "Testing ZeroDivisionError..." << std::endl;
		std::cout << "Caught ZeroDivisionError: division by zero" << std::endl;
	}
}

int	main(void)
{
	std::cout << "=== Garden Error Types Demo ==="
				<< "\n\n";
	garden_operations(12, 21, "missing.txt");
}
