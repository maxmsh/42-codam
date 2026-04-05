#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    int i = 1;

    cout << "=== Player Score Analytics ===\n\n";
    try
    {
        if (argc > 2)
        {
            cout << "Scores processed: [";
            while (argc > i)
            {
                cout << argv[i];
                i++;
                if (i < argc)
                    cout << ", ";
                else if (i == argc)
                    cout << "]";
            }
            cout << "\nTotal players: " << argc - 1 << '\n';
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}