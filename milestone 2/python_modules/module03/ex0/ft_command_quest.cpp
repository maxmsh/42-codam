#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    string program_name = argv[0];
    int args_received = argc - 1;
    int i = 1;

    cout << "=== Command Quest === \n\n";
    if (argc == 1)
    {
        cout << "No arguments provided!\n";
        cout << "Program name: " << program_name << '\n';
        cout << "Total arguments: " << argc << endl;
    }
    else if (argc > 1)
    {
        cout << "Program name: " << program_name << '\n';
        cout << "Arguments received: " << args_received << '\n';
        while (i < argc)
        {
            cout << "Argument " << i << ": " << argv[i] << '\n';
            i++;
        }
        cout << "Total arguments: " << argc << '\n';
    }
}