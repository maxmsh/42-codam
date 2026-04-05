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

    void check_plant_health(void)
    {
        cout << "\nChecking plant health...\n";
        for (const Plant &plant : plants)
        {
            if ((!plant.name.empty()) && (plant.water >= 1 && plant.water <= 10) && (plant.sun >= 2 && plant.sun <= 12))
                    cout <<  plant.name << ": healthy (water: " << plant.water << ", " << "sun: " << plant.sun << ")" << endl;
            try
            {
                if (plant.water <= 1)
                    throw WaterError("low_water");
                else if (plant.water >= 10)
                    throw WaterError("high_water");
            }
            catch(const WaterError &e)
            {
                if (strcmp(e.what(), "low_water") == 0)
                    cerr << "Error checking " << plant.name << ": Water level " << plant.water << " is too low (min 1)\n";
                else if (strcmp(e.what(), "high_water") == 0)
                    cerr << "Error checking " << plant.name << ": Water level " << plant.water << " is too high (max 10)\n";
            }
            try
            {
                if (plant.sun <= 2)
                    throw PlantError("low_plant");
                else if (plant.sun >= 12)
                    throw PlantError("high_plant");
            }
            catch(const PlantError& e)
            {
                if (strcmp(e.what(), "low_plant") == 0)
                    cerr << "Error checking " << plant.name << ": Sunlight hours " << plant.sun << " is too low (min 2)\n";
                else if (strcmp(e.what(), "high_plant") == 0)
                    cerr << "Error checking " << plant.name << ": Sunlight hours " << plant.sun << " is too high (max 12)\n";
            }
            
        }
    }
};

int check_garden_management()
{
    GardenManager manager;

    manager.add_plant("tomato", 5, 8);
    manager.add_plant("lettuce", 15, 3);
    manager.add_plant("", 0, 0);

    manager.water_plants();

    manager.check_plant_health();

    return 0;
}

int main(void)
{
    cout << "=== Garden Management System ===\n\n";
    check_garden_management();
    cout << "\nGarden management system test complete!" << endl;
}