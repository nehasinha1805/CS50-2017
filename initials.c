#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
    string name = GetString();
    
    printf("%c", toupper(name[0]));
    
    for (int i = 1, n = strlen(name); i < n; i++)
    {
        if(name[i] == ' ')
        {
            i++;
            printf("%c", toupper(name[i]));
        }
    }
    printf("\n");
}