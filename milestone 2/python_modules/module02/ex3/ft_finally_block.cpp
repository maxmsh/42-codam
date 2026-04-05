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

void test_watering_system(int errors)
{
    cout << "=== Garden Watering System ===\n\n";

    vector<Plant> plants = {
        {"tomato", 4, 6}
    };

    
}

int main(void)
{
    cout << "=== Garden Watering System ===\n";
    test_watering_system(0);
    test_watering_system(1);
    cout << "\nCleanup always happens, even with errors!" << endl;
}