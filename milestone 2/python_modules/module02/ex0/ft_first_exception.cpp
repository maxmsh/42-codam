#include <iostream>
#include <string>
#include <cstring>

int	check_temperature(std::string temp_str)
{
	int	typecasted;

	typecasted = 0;
	std::cout << "\n"
				<< "Testing temperature: " << temp_str << "\n";
	try
	{
		typecasted = std::stoi(temp_str);
		if (typecasted > 40)
		{
			throw std::invalid_argument("hot");
		}
		else if (typecasted < 0)
		{
			throw std::invalid_argument("cold");
		}
		else
		{
			std::cout << typecasted << "°C is perfect for plants!" << std::endl;
		}
	}
	catch (const std::invalid_argument &e)
	{
		if (std::strcmp(e.what(), "hot") == 0)
		{
			std::cout << "Error: " << typecasted << "°C is too hot for plants (max 40°C)" << std::endl;
		}
		else if (std::strcmp(e.what(), "cold") == 0)
		{
			std::cout << "Error: " << typecasted << "°C is too cold for plants (min 0°C)" << std::endl;
		}
		else
		{
			std::cout << "Error: " << temp_str << " is not a valid number" << std::endl;
		}
	}
	return (typecasted);
}

void test_temperature_input()
{
	std::cout << "=== Garden Temperature Checker ===" << "\n";
	check_temperature("25");
	std::cout << "\n";
	check_temperature("abc");
	std::cout << "\n";
	check_temperature("100");
	std::cout << "\n";
	check_temperature("-50");
	std::cout << "\n\n" << "All tests completed - program didn't crash!" << std::endl;
}

int	main(void)
{
	test_temperature_input();
}
