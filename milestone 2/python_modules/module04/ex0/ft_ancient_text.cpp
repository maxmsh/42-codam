#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class PythonError : public exception
{
    public:
    const string &message;

    PythonError(const string &message) :
    message(message) {}

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

int main(int argc, char **argv)
{
    string filename = argv[1];
    if (argc > 1)
    {
        try
        {
            cout << "=== Cyber Archives Recovery ===\n";
            cout << "Accessing file '" << filename << "'" << endl;

            if (filename.find("/etc/") != string::npos)
                throw PythonError("forbidden");
        }
        catch(const PythonError &e)
        {
            if (strcmp(e.what(), "forbidden") == 0)
                std::cerr << "Error opening file '" << filename << "': [Errno 13] Permission denied: '" << filename << "'" << '\n';
            else if (strcmp(e.what(), "notfound") == 0)
                std::cerr << "Error opening file '" << filename << "': [Errno 2]: No such file or directory: '" << filename << "'" << '\n';
        }
        
    }
}