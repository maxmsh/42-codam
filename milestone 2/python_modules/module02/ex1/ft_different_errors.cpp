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

// I have initialized all errors as individual classes that have the ability to overwrite
// e.what's output. This is done so that every time an error has been caught
// successfully, we can print a unique message to the terminal (as required by the subject).
// All classes ultimately inherit their base traits from their parent of GardenError. 

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

        // This error will print if invalid input ( = not an integer) has been entered as its value.
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

        // This error will print if the result of its equation will be zero. Since
        // it will always divide the user's input by ten, the only way to trigger
        // this error is to enter a zero as a value. 
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

        // This error will print if the filename you have specified cannot be found.
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

        // This error will print if you're looking for a value that doesn't
        // exist. 'Garden' was defined as a map at the start of the function,
        // and if you enter a value that is not in there, this error will be
        // displayed.
    }
    
    
    if (silent == true && errors > 0)
    {
        cout << "Caught an error, but program continues!\n";
    }

    return 0;
}

// test_error_types is a function that runs through the garden operations
// one by one first to check its inputs, then checks them all together whilst
// having the 'silent' boolean set to true to filter out specific error outputs
// (since I just want it to tell me whether an error has been found or not). This
// is where 'errors' comes into play: it increments every time an error has been
// caught.  

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