#include <stdio.h>

int main()
{
    char c[102];
    while (1)
    {
        fgets(c, 102, stdin);
        if (c == EOF)
            break;
        printf("%s", c);
    }
}
