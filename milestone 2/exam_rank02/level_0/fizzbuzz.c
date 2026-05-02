#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int i;
    i = 0;

    while (i <= 100)
    {
        printf("%d", i);
        if (i >= 10)
            i = i - '0';
        write(1, &i, 1);
        write(1, "\n", 1);
        i++;
    }
}