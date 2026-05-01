#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

class CustomError : public exception
{
    private:
        string full_message;
        int error_num;
    
    public:
    CustomError(int error_num, const string &message)
    : full_message("Error opening file: [Errno " + to_string(error_num) + "] " + message),
      error_num(error_num) {}

    const char* what() const noexcept override
    {
        return full_message.c_str();
    }
};

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        string filename = argv[1];
        try
        {
            cout << "=== Cyber Archives Recovery ===\n";
            cout << "Accessing file '" << filename << "'" << endl;

            if (filename.find("/etc/") != string::npos)
                throw CustomError(13, " Permission denied: '" + filename + "'");
        }
        catch(const CustomError &e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
}