#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class GardenError : public exception
{
    public:
    string message;

    GardenError(const string &message)
    : message(message) {}

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

class PlantError : public GardenError
{
    public:

    PlantError(const string &message)
    : GardenError(message) {}
};

class WaterError : public GardenError
{
    public:

    WaterError(const string &message)
    : GardenError(message) {}
};

class GardenManager
{
    public:

    vector<string> plants = {"apple tree", "cherry tree"};

    void add_plant(string name)
    {
        try
        {
            if (name.empty())
                throw PlantError("empty");
            else
            {
                plants.push_back(name);
                cout << "Added " << name << " successfully!" << endl;
            }
        }
        catch(const invalid_argument &e)
        {
            if (strcmp(e.what(), "empty") == 0)
                cerr << "Plant name cannot be empty!" << '\n';
        }
    }
};

int check_garden_management()
{

}

int main(void)
{
    cout << "=== Garden Management System ===\n";
    check_garden_management();
    cout << "\nGarden management system test complete!" << endl;
}