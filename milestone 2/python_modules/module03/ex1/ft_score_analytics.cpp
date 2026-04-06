#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    int i = 1;
    int total = 0; 

    cout << "=== Player Score Analytics ===\n\n";
    try
    {
        if (argc > 2)
        {
            cout << "Scores processed: [";
            while (argc > i)
            {
                cout << "'" << argv[i] << "'";
                i++;
                if (i < argc)
                    cout << ", ";
                else if (i == argc)
                    cout << "]";
            }
            cout << "\nTotal players: " << argc - 1;
            cout << "\nTotal score: " << total << '\n';
        }
        else if (argc < 2)
            cout << "No scores provided. Usage: clang++ " << argv[0] << " <score1> <score2>" << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}