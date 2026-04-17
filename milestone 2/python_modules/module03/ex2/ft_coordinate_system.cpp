#include <iostream>
#include <string>
#include <cstring>
#include <limits>
using namespace std;

int get_player_pos()
{

    while (true)
    {
        cout << "Enter new coordinates as floats in format 'x,y,z': ";
        try
        {
            string input = "";
            cin >> input;
            stof(input);
        }
        catch(const invalid_argument &e)
        {
            std::cerr << "Invalid syntax" << '\n';
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
    }
    return 0;
}

int main(void)
{
    cout << "=== Game Coordinate System ===\n";
    get_player_pos();
    return 0;
}