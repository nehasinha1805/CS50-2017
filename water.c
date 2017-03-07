#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("minutes: ");
    int n = GetInt();
    int b = n * 12;
    printf("bottles: %i\n", b);
}