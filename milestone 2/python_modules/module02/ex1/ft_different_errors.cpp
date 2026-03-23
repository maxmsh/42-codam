#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>
#include <limits>
#include <fstream>
#include <cstdio>
#include <bits/stdc++.h>
#include <map>

void	garden_operations(std::string num, int divisor, const char *filename)
{
	int number;
	try
	{
		number = std::stoi(num);
		if (!number)
		{
			throw std::invalid_argument("");
		}
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "Testing ValueError..." << "\n";
		std::cout << "Caught ValueError: invalid literal for int()" << "\n" << std::endl;
	}
	try
	{
		if (number == 0 || divisor == 0)
		{
			throw std::overflow_error("");
		}
	}
	catch (const std::overflow_error &e)
	{
		std::cout << "Testing ZeroDivisionError..." << "\n";
		std::cout << "Caught ZeroDivisionError: division by zero" << "\n" << std::endl;
	}
	try
	{
		FILE* file = fopen(filename, "r");	
		if (!file)
		{
			throw std::logic_error("");
		}	
	}
	catch(const std::logic_error& e)
	{
		std::cout << "Testing FileNotFoundError..." << "\n";
		std::cout << "Caught FileNotFoundError: No such file '" << filename << "'" << "\n" << std::endl;
	}
	try
	{
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int	main(void)
{
	std::cout << "=== Garden Error Types Demo ==="
				<< "\n\n";
	garden_operations("e", 0, "missing.txt");
}
