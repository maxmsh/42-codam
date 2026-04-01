#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <map>
using namespace std;

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
	catch(const invalid_argument &e)
	{
		if (silent == false && input.rfind('.') == string::npos)
		{
			cout << "\nTesting ValueError...\n";
			cerr << "Caught ValueError: invalid literal for int()" << endl;
			return 1;
		}
		else if (silent == true)
			throw SignalException();
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
	// 	else if (silent == true)
	// 		throw SignalException();
	// }
		try
		{
			if (silent == false && input.rfind('.'))
				file.open(input);
		}
		catch(const ios_base::failure &e)
		{
			cout << "\nTesting FileNotFoundError...\n";
			cerr << "Caught FileNotFoundError: No such file '" << input << "'" << endl;
			return 1;
		}
		try
		{
			if (silent == false)
			{

			}

		}
		catch(const out_of_range &e)
		{
			cout << "Testing KeyError...\n";
			cerr << "Caught KeyError: " << input << endl;
			return 1;
		}
		
	return 0;
}

void	test_error_types(void)
{
	garden_operations("abc", false);
	// garden_operations("15", false);
	garden_operations("missing.txt", false);
	garden_operations("missing_key", false);
	cout << "Testing multiple errors together...\n";
	garden_operations("s", true);
	garden_operations("8", true);
	garden_operations("orion", true);
	garden_operations("missin", true);
}

int	main(void)
{
	cout << "=== Garden Error Types Demo ==="
				<< "\n\n";
	test_error_types();
	cout << "\nAll error types tested succesfully!" << endl;
}
