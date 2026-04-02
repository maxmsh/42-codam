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
			cerr << "\nTesting " << e.name << "Error...\nCaught " << e.name << "Error: " << e.what() << endl;
		}
		else if (silent)
		{
			SignalException e("SignalError","Caught an error, but program continues!");

			cerr << "\n" << e.desc;
			return 1;
		}
	}
	// try
	// {
	// 	if (silent == false)
	// 	{
	// 		"0 / 0";
	// 	}
	// }
	// catch(const runtime_error &e)
	// {
	// 	if (silent == false)
	// 	{
	// 		cout << "\nTesting ZeroDivisionError...\n";
	// 		cerr << "Caught ZeroDivisionError: division by zero" << endl;
	// 		return 1;
	// 	}
	// }
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
	// garden_operations("abc", false);
	// garden_operations("15", false);
// 	garden_operations("missing.txt", false);
// 	garden_operations("missing_key", false);
// 	cout << "Testing multiple errors together...\n";
	garden_operations("s", true);
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
