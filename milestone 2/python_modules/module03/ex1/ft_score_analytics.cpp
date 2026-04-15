#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    string srcfile = __FILE__;
    string program_name = argv[0];
    int players = argc - 1;
    int sum = 0;
    int average;
    int i = 1;
    int max, min, range;

    bool err_output = false;

    if (argc > 2)
    {
        cout << "=== Player Score Analytics ===\n";
        while (i < argc)
        {
            try
            {
                sum += stoi(argv[i]);
            }
            catch(const std::exception &e)
            {
                err_output = true;
                std::cerr << "Invalid parameter: '" << argv[i] << "'" << '\n';
            }
            i++;
        }
        if (err_output)
        {
            cout << "No scores provided. Usage: clang++ " << srcfile << " && " << program_name << " <score1> <score2> ..." << endl;
            return 1;
        }
        else if (!err_output)
        {
            max = stoi(argv[1]);
            min = stoi(argv[1]);
            cout << "Scores processed: [";
            i = 1;
            while (i < argc)
            {
                int val = stoi(argv[i]);

                if (val > max)
                    max = val;
                if (val < min)
                    min = val;

                cout << argv[i];
                i++;
                if (i < argc)
                    cout << ", ";
                else if (i == argc)
                    cout << "]" << endl;
            }
            cout << "Total players: " << players << endl;
            cout << "Total score: " << sum << endl;
            average = sum / players;
            cout << "Average score: " << average << endl;
            cout << "High score: " << max << endl;
            cout << "Low score: " << min << endl;
            range = max - min;
            cout << "Score range: " << range << endl;
        }
    }
    else
        cout << "No scores provided. Usage: clang++ " << srcfile << " && " << program_name << " <score1> <score2> ..." << endl;
    
    return 0;
}