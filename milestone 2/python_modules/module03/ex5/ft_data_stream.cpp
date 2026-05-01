#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

void gen_event()
{
    int i = 0;

    srand(time(0));
    vector<string> players = {
        "alice", "bob", "charlie", "dylan"
    };
    vector<string> actions = {
        "run", "eat", "sleep", "grab", "move", "climb", "swim", "release", "use"
    };

    while (i < 100)
    {
        for (string &player : players)
        {
            for (string &action : actions)
            {
                cout << "Player " << player << " performed an action: " << action << endl;
                i++;
            }
        }
    }
}

int main(void)
{
    cout << "=== Game Data Stream Processor ===\n";
    gen_event();

    return 0;
}