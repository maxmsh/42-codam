#include <iostream>
#include <string>

int	check_temperature(std::string temp_str)
{
	int typecasted = 0;

	std::cout << "\n" << "Testing temperature: " << temp_str << "\n";

	try
	{
	typecasted = std::stoi(temp_str);

	if (typecasted >= 40)
	{
		throw std::out_of_range("hot");
	}
	else if (typecasted <= 0)
	{
		throw std::out_of_range("cold");
	}
	else if (typecasted > 0 && typecasted < 40)
	{
		std::cout << typecasted << "°C is perfect for plants!" << std::endl;
	}
	}
	catch (const std::invalid_argument&e)
	{
		std::cout << temp_str << " is not a valid number" << std::endl;
	}
	catch (const std::out_of_range&e)
	{
		if (std::string(e.what()) == "hot")
		{
			std::cout << typecasted << "°C is too hot for plants (max 40°C)" << std::endl;
		}
		else if (std::string(e.what()) == "cold")
		{
			std::cout << typecasted << "°C is too cold for plants (min 0°C)" << std::endl;
		}
	}
	return typecasted;
}

int main(void)
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
