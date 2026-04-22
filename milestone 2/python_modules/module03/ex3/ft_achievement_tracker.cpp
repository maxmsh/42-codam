#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {
public:
    string name;
    vector<string> achievements;

    Player(string n, vector<string> a) : name(n), achievements(a) {}
};

vector<string> get_random_achievements(vector<string>& all_achievements)
{
    vector<string> result;
    vector<string> pool = all_achievements;

    int max = all_achievements.size();

    int count = rand() % max;

    for (int i = 0; i < count; i++)
    {
        int index = rand() % pool.size();
        result.push_back(pool[index]);
        pool.erase(pool.begin() + index);
    }

    if (result.empty())
        return {"set()"};

    return result;
}

int main(void)
{
    srand(time(0));

    cout << "=== Achievement Tracker System ===" << endl;

    vector<string> achievements = {
        "Crafting Genius", "Strategist", "World Savior", "Speed Runner", "Survivor",
        "Master Explorer", "Treasure Hunter", "Unstoppable", "First Steps",
        "Collector Supreme", "Untouchable", "Sharp Mind", "Boss Slayer", "Hidden Path Finder"
    };

    vector<Player> players = {
        Player("Alice",   get_random_achievements(achievements)),
        Player("Bob",     get_random_achievements(achievements)),
        Player("Charlie", get_random_achievements(achievements)),
        Player("Dylan",   get_random_achievements(achievements))
    };

    for (Player p : players)
    {
        cout << "\nPlayer " << p.name << ": ";
        for (int i = 0; i < p.achievements.size(); i++)
        {
            cout << "{'" << p.achievements[i] << "'}";
            if (i < p.achievements.size() - 1)
                cout << ", ";
            else if (i == p.achievements.size() - 1)
                cout << endl;
        }
    }

    return 0;
}