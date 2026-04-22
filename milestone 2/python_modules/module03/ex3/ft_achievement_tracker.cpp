#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player
{
    public:
        string name;
        string achievement;

    Player(string n, string a) : name(n), achievement(a) {}
};


vector <Player> gen_player_achievements()
{
    vector <string> achievements = {
        "Crafting Genius", "Strategist", "World Savior", "Speed Runner", "Survivor",
        "Master Explorer", "Treasure Hunter", "Unstoppable", "First Steps",
        "Collector Supreme", "Untouchable", "Sharp Mind", "Boss Slayer", "Hidden Path Finder"
    };

    int max = achievements.size();

    vector <Player> players = {
        Player("Alice", achievements[rand() % max]),
        Player("Bob", achievements[rand() % max]),
        Player("Charlie", achievements[rand() % max]),
        Player("Dylan", achievements[rand() % max])
    };

    return players;
}

int main(void)
{
    srand(time(0));

    vector <Player> players = gen_player_achievements();

    for (Player p: players)
    {
        cout << "Player " << p.name << " has achievement: " << p.achievement << endl; 
    }
    return 0;
}