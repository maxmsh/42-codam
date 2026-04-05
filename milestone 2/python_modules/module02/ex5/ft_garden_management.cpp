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

struct Plant
{
    string name;
    int water, sun;
};

class GardenManager
{
    public:

    vector<Plant> plants;

    void add_plant(string name, int water, int sun)
    {
        try
        {
            if (name.empty())
                throw PlantError("empty");
            else
            {
                plants.push_back({name, water, sun});
                cout << "Added " << name << " successfully!" << endl;
            }
        }
        catch(const PlantError&e)
        {
            if (strcmp(e.what(), "empty") == 0)
                cerr << "Plant name cannot be empty!" << '\n';
        }
    }

    void water_plants(void)
    {
        cout << "\nOpening watering system\n";
        for (const Plant &plant : plants)
        {
            if (!plants.empty())
                cout << "Watering " << plant.name << " - success\n";
        }
        cout << "Closing watering system (cleanup)\n";
    }
};

int check_garden_management()
{
    GardenManager manager;

    manager.add_plant("tomato", 1, 3);
    manager.add_plant("lettuce", 2, 15);
    manager.add_plant("", 0, 0);

    manager.water_plants();

    return 0;
}

int main(void)
{
    cout << "=== Garden Management System ===\n\n";
    check_garden_management();
    cout << "\nGarden management system test complete!" << endl;
}