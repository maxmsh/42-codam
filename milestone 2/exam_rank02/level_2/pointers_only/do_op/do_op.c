#include <unistd.h>

void do_op(char *first, char *operation, char *second)
{
    int result;

    if (*operation == '+')
        result = *(first + *second);
    else if (*operation == '-')
        result = *(first - *second);
    else if (*operation == '*')
        result = *(first * *second);

    write(1, &result, 1);
}

int main(int argc, char **argv)
{
    if (argc == 4)
        do_op(argv[1], argv[2], argv[3]);
    else
        write(1, "\n", 1);
    
    return (0);
}