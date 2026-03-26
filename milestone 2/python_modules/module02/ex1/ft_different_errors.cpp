#include <iostream>
#include <string>

int	garden_operations(const std::string &input)
{
	try
	{
		return (std::stoi(input));
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "Caught ValueError: invalid literal for int()" << std::endl;
	}
}

void	test_error_types(void)
{
	std::cout << "Testing ValueError..."
				<< "\n";
	garden_operations("abc");
}

int	main(void)
{
	std::cout << "=== Garden Error Types Demo ==="
				<< "\n\n";
	test_error_types();
}
