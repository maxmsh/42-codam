#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class ZeroDivisionError : public std::exception
{
	public:
	const char* what() const noexcept override
	{
		return "\nCaught ZeroDivisionError: ";
	}
};

class FileNotFoundError : public std::exception
{
	public:
	const char* what() const noexcept override
	{
		return "\nCaught FileNotFoundError: ";
	}
};

class KeyError : public std::exception
{
	public:
	const char* what() const noexcept override
	{
		return "\nCaught KeyError: ";
	}
};

class SignalException : public std::exception
{
	public:
	const char* what() const noexcept override
	{
		return "\nCaught an error, but program continues!";
	}
};

int	garden_operations(const string &input, bool silent)
{
	int num, result;
	double numb;
	try
	{
		if (silent == false)
		{
			cout << "\nTesting ValueError...\n";
			num = stoi(input);
		}
	}
	catch(const invalid_argument &e)
	{
		if (silent == false)
			cerr <<"Caught ValueError: invalid literal for int()" << endl;
		else
			throw SignalException();
	}
	try
	{
		if (silent == false)
		{
			cout << "\nTesting ZeroDivisionError..." << endl;
			// numb = (num * 1.0);
			// result = (numb / 0);
			// return result;
		}
	}
	catch(const runtime_error &e)
	{
		if (silent == false)
			throw ZeroDivisionError();
		else
			throw SignalException();
	}
	
	
	return 0;
}

void	test_error_types(void)
{
	garden_operations("abc", false);
	garden_operations("15", false);
}

int	main(void)
{
	cout << "=== Garden Error Types Demo ==="
				<< "\n\n";
	test_error_types();
	cout << "\nAll error types tested succesfully!" << endl;
}
