#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
using namespace std;

int get_player_pos()
{

    while (true)
    {
        cout << "Enter new coordinates as floats in format 'x,y,z': ";
        try
        {
            string input;
            cin >> input;

            stringstream ss(input);
            string token;
            vector<float> coords;
            
            while (getline(ss, token, ','))
            {
                coords.push_back(stof(token));
            }

            float x = coords[0];
            float y = coords[1];
            float z = coords[2];

            cout << "You have entered: " << coords[0] << ", " << coords[1] << ", and " << coords[2] << "." << endl;
            break;
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