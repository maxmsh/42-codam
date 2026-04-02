#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;

class GardenError : public std::exception
{
    public:
    string name, desc;

    GardenError(const string& name, const string& desc)
    : name(name), desc(desc) {}

    const char* what() const noexcept override
    {
        return desc.c_str();
    }
};

// Here I am creating a class called GardenError that inherits its base traits from
// the standardized exception class. For our intents and purposes, it's  going to serve
// as a template for both the PlantClass and WaterClass that follow after this one.
// It contains a string for its name to differentiate between specific error types
// and also a description that will tell you what went wrong. 

class PlantError : public GardenError
{
    public:
    PlantError(const string& name, const string& desc)
    : GardenError(name, desc) {}
};

class WaterError : public GardenError
{
    public:
    WaterError(const string& name, const string& desc)
    : GardenError(name, desc) {}
};

// PlantError and WaterError inherit virtually everything from their parent class, GardenError.
// The only things that truly differ are its variable values: the names and descriptions of
// each of the errors generated.

void check_garden()
{
    throw GardenError("garden", "The tomato plant is wilting!");
}

void check_garden_again()
{
    throw GardenError("garden", "Not enough water in the tank!");
}

void check_plant()
{
    throw PlantError("Plant", "The tomato plant is wilting!");
}

void check_water()
{
    throw WaterError("Water", "Not enough water in the tank!");
}

int custom_garden_errors()
{
    try
    {
        check_plant();
    }
    catch (const PlantError &e)
    {
        cerr << "\nTesting " << e.name << "Error...\nCaught " << e.name << "Error: " << e.desc << endl;
    }
    try
    {
        check_water();
    }
    catch(const WaterError &e)
    {
        cerr << "\nTesting " << e.name << "Error...\nCaught " << e.name << "Error: " << e.desc << endl;
    }
    cout << "\nTesting catching all garden errors...";

    vector<void(*)()> functions = {check_garden, check_garden_again};

    for (auto func: functions)
    {
        try
        {
            func();
        }
        catch (const GardenError &e)
        {
            cerr << "\nCaught a " << e.name << " error: " << e.desc;
        }
    }
    return 0;
}

int main(void)
{
    cout << "=== Custom Garden Errors Demo === \n";
    custom_garden_errors();
    cout << "\nAll custom error types work correctly!" << endl;
    return 0;
}