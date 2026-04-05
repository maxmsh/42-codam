#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Error : public exception
{
    public:
    string message;

    Error(const string &message)
    : message(message) {}

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

struct Plant
{
    string name;
    int water, sun;
};

void test_watering_system(void)
{
    int errors = 0;

    vector<Plant> plants = {
        {"tomato", 4, 6},
        {"lettuce", 2, 17},
        {"carrots", 2, 17}
    };
    vector<Plant> error = {
        {"tomato", 4, 5},
        {"None", 8, 3}
    };
    
    cout << "\nTesting normal watering...\nOpening watering system\n";
    for (Plant &plant : plants)
    {
        try
        {
            if ((!plant.name.empty()) && (plant.name != "None"))
                cout << "Watering " << plant.name << "\n";
            else
                throw Error("empty");
        }
        catch(const Error &e)
        {
            errors++;
             if (strcmp(e.what(), "empty") == 0)
                cerr << "Error: cannot water " << plant.name << " - invalid plant!" << '\n';
        }
    }
    cout << "Closing watering system (cleanup)" << endl;
    if (errors == 0)
        cout << "Watering completed successfully!\n\n";
    cout << "\nTesting with error...\nOpening watering system\n";
    for (Plant &plant : error)
    {
        try
        {
            if ((!plant.name.empty()) && (plant.name != "None"))
                cout << "Watering " << plant.name << "\n";
            else
                throw Error("empty");
        }
        catch(const Error &e)
        {
            errors++;
            if (strcmp(e.what(), "empty") == 0)
                cerr << "Error: cannot water " << plant.name << " - invalid plant!" << '\n';
        }
    }
    cout << "Closing watering system (cleanup)" << endl;
    if (errors == 0)
        cout << "Watering completed successfully!\n";
}

int main(void)
{
    cout << "=== Garden Watering System ===\n\n";
    test_watering_system();
    cout << "\nCleanup always happens, even with errors!" << endl;
}