#include <unistd.h>

void putnum(char c)
{
    
}

void fizzbuzz(int len)
{
    int i;
    i = 0;

    while (i <= len)
    {
        write(1, &i, 1);
        i++;
    }
}

int main()
{
    fizzbuzz(100);
}