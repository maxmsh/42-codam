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
    float distance, distance_sec;

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
            distance = sqrt(x*x + y*y + z*z);
            cout << "Distance to center: " << setprecision(5) << distance << endl;
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

                distance_sec = sqrt(x2*x2 + y2*y2 + z2*z2);
                float calculated = (distance_sec - distance);

                cout << "Distance between the two sets of coordinates: " << setprecision(5) << calculated << endl;
                break;
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