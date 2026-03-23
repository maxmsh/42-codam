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
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "Testing ValueError..." << std::endl;
		std::cout << "Caught ValueError: invalid literal for int()" << std::endl;
	}
}

int	main(void)
{
	std::cout << "=== Garden Error Types Demo ==="
				<< "\n\n";
	garden_operations('p', 21, "missing.txt");
}
