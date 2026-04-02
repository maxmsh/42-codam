#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class ValueError : public std::exception
{
    public:
    string name, desc;
    
    ValueError(const string &name, const string &desc)
    : name(name), desc(desc) {}

    const char* what() const noexcept override
    {
        return desc.c_str();
    }
};

int check_plant_health(string plant_name, int water_level, int sunlight_hours)
{
    try
    {
        if (plant_name.empty())
            throw ValueError("NameError", "Plant name cannot be empty!");
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    try
    {
        if (water_level <= 1)
            throw ValueError("ValueError", "low");
        else if (water_level >= 10)
            throw ValueError("ValueError", "high");
    }
    catch(const std::exception& e)
    {
        if (strcmp(e.what(), "low") == 0)
            std::cerr << "Error: Water level " << water_level << " is too low (min 1)" << '\n';
        else if (strcmp(e.what(), "high") == 0)
            std::cerr << "Error: Water level " << water_level << " is too high (max 10)" << '\n';
    }

    try
    {
        if (sunlight_hours <= 2)
            throw ValueError("ValueError", "cold");
        else if (sunlight_hours >= 12)
            throw ValueError("ValueError", "hot");
    }
    catch(const std::exception& e)
    {
        if (strcmp(e.what(), "cold") == 0)
            std::cerr << "Error: Sunlight hours " << sunlight_hours << " is too low (min 2)" << '\n';
        else if (strcmp(e.what(), "hot") == 0)
            std::cerr << "Error: Sunlight hours " << sunlight_hours << " is too high (max 12)" << '\n';
    }
    
    if ((!plant_name.empty()) && (water_level >= 1 && water_level <= 10) && (sunlight_hours >= 2 && sunlight_hours <= 12))
    {
        cout << "Plant '" << plant_name << "' is healthy!" << endl; 
    }
    return 0;
}

void test_plant_checks(void)
{
    cout << "\nTesting good values...\n";
    check_plant_health("tomato", 3, 8);
    cout << "\nTesting empty plant name...\n";
    check_plant_health("", 2, 1);
    cout << "\nTesting bad water level...\n";
    check_plant_health("tomato", 15, 4);
    cout << "\nTesting bad sunlight hours...\n";
    check_plant_health("tomato", 4, 0);
}

int main(void)
{
    cout << "=== Garden Plant Health Checker ===\n";
    test_plant_checks();
    cout << "\nAll error raising tests completed!" << endl;
}