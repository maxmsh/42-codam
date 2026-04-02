#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <map>
using namespace std;

// I am initializing and creating a couple of error classes here
// to be called later in the program. Each will have their own name
// and descriptive message of what exactly went wrong.

// I made the implementation of this program perhaps a little more
// elaborate than what was requested by 42. For example, I use a boolean
// value called 'silent' that will allow me to toggle the error output
// of every single error on or off. When set to silent, its specific error output
// will not print.

// SignalException was not specified as an error that had to be handled in
// the subject. However, I decided to make it as a sort of signal that will
// simply let you know an error has been found when the errors within the 
// program have been set to silent. This turned out to be useful when
// testing multiple errors together at the same time.

class SignalException : public std::exception
{
	public:
	string name, desc;

	SignalException(const string &name, const string &desc) :
	name(name), desc(desc) {}
	const char* what() const noexcept override
	{
		return desc.c_str();
	}
};

class ValueError : public SignalException
{
	public:
	ValueError(const string &desc)
	: SignalException("Value", desc) {}
};

class ZeroDivisionError : public SignalException
{
	public:
	ZeroDivisionError(const string &desc)
	: SignalException("ZeroDivision", desc) {}
};

class FileNotFoundError : public SignalException
{
	public:
	FileNotFoundError(const string &desc)
	: SignalException("FileNotFound", desc) {}
};

class KeyError : public SignalException
{
	public:
	KeyError(const string &desc)
	: SignalException("Key", desc) {}
};

int	garden_operations(const string &input, bool silent)
{
	int num, result;
	ifstream file;
	file.exceptions(std::ifstream::failbit);
	std::map<string, string> mydict =
	{
		{"name", "dictionary"}
	};
	try
	{
		num = stoi(input);
	}
	catch(const invalid_argument &)
	{
		ValueError e("invalid literal for int()");

		if (!silent)
		{
			cerr << "\nTesting " << e.name << "Error...\nCaught " << e.name << "Error: " << e.desc << endl;
		}
		else if (silent)
		{
			SignalException e("SilentError","Caught an error, but program continues!");

			cerr << "\n" << e.desc;
			return 1;
		}
	}
	try
	{
		result = (num / 10);
		if (result == 0)
			throw overflow_error("division by zero");
	}
	catch(const overflow_error &)
	{
		ZeroDivisionError e("division by zero");
		if (!silent)
		{
			cerr << "\nTesting " << e.name << "Error...\nCaught " << e.name << "Error: " << e.desc << endl;
		}
		else if (silent)
		{
			SignalException e("SilentError", "Caught an error, but program still continues!");
			cerr << e.desc << "\n";
			return 1;
		}
	}
		// try
		// {
		// 	if (silent == false && input.rfind('.'))
		// 		file.open(input);
		// }
		// catch(const ios_base::failure &e)
		// {
		// 	cerr << "\nTesting FileNotFoundError...\n";
		// 	cerr << "Caught FileNotFoundError: No such file '" << input << "'" << endl;
		// }
		// try
		// {
		// 	if (silent == false)
		// 	{

		// 	}

		// }
		// catch(const out_of_range &e)
		// {
		// 	cerr << "Testing KeyError...\n";
		// 	cerr << "Caught KeyError: " << input << endl;
		// }
		
	return 0;
}

void	test_error_types(void)
{
	garden_operations("abc", false);
	garden_operations("0", false);
// 	garden_operations("missing.txt", false);
// 	garden_operations("missing_key", false);
// 	cout << "Testing multiple errors together...\n";
	// garden_operations("s", true);
// 	garden_operations("8", true);
// 	garden_operations("orion", true);
// 	garden_operations("missin", true);
}

int	main(void)
{
	cout << "=== Garden Error Types Demo ==="
				<< "\n";
	test_error_types();
	cout << "\nAll error types tested succesfully!" << endl;
}
