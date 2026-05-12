#include <unistd.h>

void print_hex()
{

}

int main(int argc, char **argv)
{
    if (argc == 2)
        print_hex(argv[1]);
    else
        write(1, "\n", 1);

    return (0);
}