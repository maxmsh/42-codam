#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    string srcfile = __FILE__;
    string program_name = argv[0];
    int players = argc - 1;
    int i = 1;
    int sum = 0;

    bool invalid_found = false;


    if (argc > 2)
    {
        cout << "=== Player Score Analytics ===\n";
        try
        {
            cout << "Scores processed: [";
            while (argc > i)
            {
                cout << argv[i];
                i++;
                if (i < argc)
                    cout << ", ";
                else if (i == argc)
                    cout << "]" << '\n';
            }
            cout << "Total players: " << players << '\n';
            cout << "Total score: " << sum << '\n';
        }
        catch(const std::invalid_argument &e)
        {
            std::cerr << e.what() << '\n';
            invalid_found = true;
        }
        
    }
    else
        cout << "No scores provided. Usage: clang++ " << srcfile << " && " << program_name << " <score1> <score2> ..." << endl;

    return 0;
}