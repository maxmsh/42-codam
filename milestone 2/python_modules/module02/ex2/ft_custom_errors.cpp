#include <iostream>
#include <string>
#include <stdexcept>
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

// Here I am creating a class called GardenError that's going to be functioning
// as a template for both the PlantClass and WaterClass that follow after this one.
// It contains a string for its name to differentiate between specific error types
// and also a description that will tell you what went wrong. 

class PlantError : public GardenError
{

};

class WaterError : public GardenError
{

};

void check_garden()
{
    throw GardenError("garden", "The tomato plant is wilting!");
}

void check_garden_again()
{
    throw GardenError();
}

int custom_garden_errors()
{
    try
    {
        check_garden();
    }
    catch (const GardenError &e)
    {
        cerr << "\nTesting " << GardenError.name << "Error"
    }
    return 0;
}

int main(void)
{
    cout << "=== Custom Garden Errors Demo === \n\n";
    custom_garden_errors();
    cout << "All custom error types work correctly!" << endl;
    return 0;
}