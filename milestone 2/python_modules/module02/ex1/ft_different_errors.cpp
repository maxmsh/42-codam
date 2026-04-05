#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

class GardenError : public std::exception
{
    public:
    string name, desc;

    GardenError(const string &name, const string &desc)
    : name(name), desc(desc) {}

    const char* what() const noexcept override
    {
        return desc.c_str();
    }
};

class ValueError : public GardenError
{
    public:
    ValueError(const string &name, const string &desc)
    : GardenError(name, desc) {}
};

class ZeroDivisionError : public GardenError
{
    public:
    ZeroDivisionError(const string &name, const string &desc)
    : GardenError(name, desc) {}
};

class FileNotFoundError : public GardenError
{
    public:
    FileNotFoundError(const string &name, const string &desc)
    : GardenError(name, desc) {}
};

class KeyError : public GardenError
{
    public:
    KeyError(const string &name, const string &desc)
    : GardenError(name, desc) {}
};

// Here I initialize a class with two variables that can overwrite
// the standard message output of an error in e.what(). 

int garden_operations(string input, int divisor, string filename, string key, bool silent)
{
    int result, errors;
    errors = 0;

    map<string, int> garden = {
        {"roses", 3},
        {"tulips", 7},
        {"sunflowers", 2}
    };

    try
    {
        int num = stoi(input);
    }
    catch(const invalid_argument &)
    {
        ValueError e("ValueError", "invalid literal for int()");

        errors++;
        if (silent == false)
        {
            cerr << "Caught " << e.name << ": " << e.what() << '\n';
        }
    }
    
    try
    {
        result = (divisor / 10);

        if (divisor == 0)
            throw overflow_error("");
    }
    catch(const overflow_error &)
    {
        ZeroDivisionError e("ZeroDivisionError", "division by zero");

        errors++;
        if (silent == false)
        {
            cerr << "Caught " << e.name << ": " << e.what() << '\n';
        }
    }

    try
    {
        ifstream file(filename);
        if (!file.is_open())
            throw runtime_error("");
    }
    catch(const runtime_error &)
    {
        FileNotFoundError e("FileNotFoundError", "No such file ");

        errors++;
        if (silent == false)
        {
            cerr << "Caught " << e.name << ": " << e.what() << "'" << filename << "'" << '\n';
        }
    }
    
    try
    {
        garden.at(key);
    }
    catch(const out_of_range &)
    {
        KeyError e("KeyError", "");

        errors++;
        if (silent == false)
        {
            cerr << "Caught "  << e.name << ": '" << key << "'" << '\n';
        }
    }
    
    
    if (silent == true && errors > 0)
    {
        cout << "Caught an error, but program continues!\n";
    }

    return 0;
}

void test_error_types()
{
    cout << "\nTesting ValueError...\n";
    garden_operations("abc", 2, "ft_different_errors.cpp", "roses",  false);
    cout << "\nTesting ZeroDivisionError...\n";
    garden_operations("67", 0, "ft_different_errors.cpp", "roses", false);
    cout << "\nTesting FileNotFoundError...\n";
    garden_operations("15", 9, "missing.txt", "roses", false);
    cout << "\nTesting KeyError...\n";
    garden_operations("3", 11, "ft_different_errors.cpp", "missing_plant", false);

    cout << "\nTesting multiple errors...\n";
    garden_operations("abc", 0, "missing.txt", "missing_plant", true);
}

int main(void)
{
    cout << "=== Garden Error Types Demo ===\n";
    test_error_types();
    cout << "\nAll error types tested successfully!" << endl;
}