#include <stdio.h>

int main()
{
    char c[102];
    while(c!=EOF){
        gets(c);
        printf("%s",c);
    }
}
