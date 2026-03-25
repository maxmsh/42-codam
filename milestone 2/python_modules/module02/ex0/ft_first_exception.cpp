#include <iostream>
#include <string>
#include <cstring>

int	check_temperature(std::string temp_str)
{
	int	typecasted; 

	// typecasted is a variable that stores integer (whole number)
	// data extracted from the string input variable temp_str.
	// The input data from temp_str gets converted using the stoi method (string to integer).
	// It has its default value set to 0 to prevent random garbage values. 

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
	
	// My try block contains some conditional logic; depending on what input is entered,
	// a different message will be printed to the terminal. 
	// If the input is somewhere between 40 and 0, it will tell you
	// that the temperature value you have entered is suitable for plant growth.
	// If not, then it will either tell you that your input value was
	// too hot or too cold to foster proper plant growth. 

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

	// Here we actually catch the errors we saw previously.
	// I used strcmp to make sure that the error messages were
	// compared the right way as it would only compare the first
	// character of the string when I would try it any other way.

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

// As per the subject change, 42 now requires a testing function named
// test_temperature_input() for this exercise. I mainly used this function as a placeholder
// for a couple of value tests as I couldn't figure out much use for it myself. 

int	main(void)
{
	test_temperature_input();
}
