#include <iostream>
#include <string>

int	garden_operations(const std::string &input)
{
	try
	{
		int number = std::stoi(input);
		if (!number)
			throw std::invalid_argument("invalid literal for int()\n");
		if (number == 0)
			throw std::runtime_error("division by zero\n");
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "Caught ValueError: " << e.what() << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cout << "Caught ZeroDivisionError: " << e.what() << std::endl;
	}
	return 0;
}

void	test_error_types(void)
{
	std::cout << "\nTesting ValueError...\n";
	garden_operations("abc");
	std::cout << "\nTesting ZeroDivisionError...\n";
	garden_operations("15");
	std::cout << "\n";
}

int	main(void)
{
	std::cout << "=== Garden Error Types Demo ==="
				<< "\n";
	test_error_types();
}
