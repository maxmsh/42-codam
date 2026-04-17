#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int get_player_pos()
{
    bool first = true, second = false;

    cout << "Enter a first set of coordinates\n";
    while (first == true)
    {
        cout << "Enter new coordinates as floats in format 'x,y,z': ";
            string input;
            cin >> input;

            stringstream ss(input);
            string token;
            vector<float> coords;
        try
        {
            while (getline(ss, token, ','))
            {
                coords.push_back(stof(token));
            }

            float x = coords[0];
            float y = coords[1];
            float z = coords[2];

            cout << "Got a first tuple: " << coords[0] << ", " << coords[1] << ", " << coords[2]  << endl;
            cout << "It includes: X=" << coords[0] << " Y=" << coords[1] << " Z=" << coords[2] << endl;
            int distance = sqrt(coords[0] * 2 + coords[1] * 2 + coords[2] * 2);
            cout << "Distance to center: " << distance << setprecision(4) << endl;
            first = false;
            second = true;
        }
        catch(const invalid_argument &e)
        {
            std::cerr << "Invalid syntax" << '\n';
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (first == false && second == true)
                cout << "\nEnter a second set of coordinates\n";
        while (second == true)
        {
            cout << "Enter new coordinates as floats in format 'x,y,z': ";
                string input;
                cin >> input;

                stringstream ss(input);
                string token;
                vector<float> sec_coords;
            try
            {
                while(getline(ss, token, ','))
                {
                    sec_coords.push_back(stof(token));
                }

                float x2 = sec_coords[0];
                float y2 = sec_coords[1];
                float z2 = sec_coords[2];
            }
            catch(const invalid_argument &e)
            {
                std::cerr << "Error on parameter '" << token << "' : could not convert string to float: '" << token << "'" << '\n';
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            
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