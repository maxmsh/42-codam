#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    std::cout << "=== Game Data Alchemist ===\n" << endl;

    vector <string> players = {
        "Alice", "bob", "Charlie", "dylan", "Emma", "Gregory", "john", "kevin", "Liam"
    };

    std::cout << "Initial list of players: ";
    for (int i = 0; i < players.size(); i++)
    {
        std::cout << players[i];
        if (i < players.size() - 1)
            std::cout << ", ";
    }
    std::cout << endl;
    std::cout << "\nNew list with all names capitalized: ";
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i][0] >= 97 && players[i][0] <= 122)
            players[i][0] -= 32;
        std::cout << players[i];
        if (i < players.size() - 1)
            std::cout << ", ";
    }
    std::cout << endl;
    std::cout << "\nNew list of capitalized names only: ";
    vector <string> cap_only;
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i][0] >= 65 && players[i][0] <= 90)
            cap_only.push_back(players[i]);
    }
    for (int i = 0; i < cap_only.size(); i++)
    {
        
    }
    std::cout << endl;
}