#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    std::cout << "=== Game Data Alchemist ===\n" << endl;

    vector <string> players = {
        "Alice", "bob", "Charlie", "dylan", "Emma", "Gregory", "john", "kevin", "Liam"
    };

    vector <string> duplicate = {
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
    for (int i = 0; i < duplicate.size(); i++)
    {
        if (duplicate[i][0] >= 65 && duplicate[i][0] <= 90)
            std::cout << duplicate[i];

        if (i < duplicate.size() - 1)
            std::cout << ", ";
    }
    std::cout << endl;
}