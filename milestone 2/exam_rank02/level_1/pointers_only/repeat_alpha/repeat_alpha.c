#include <unistd.h>

void repeat_alpha(char *str)
{

}

int main(int argc, char **argv)
{
    if (argc == 2)
        repeat_alpha(argv[1]);
    else
        write(1, "\n", 1);
    
    return (0);
}