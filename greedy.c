#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    float f, i;
    int a;
    int count = 0;
    do
    {
        printf ("O hai! How much change is owed?\n");
        f = GetFloat();
        i = round(f * 100.00);
        a = (int)i;
    }while (a < 0);
    do 
    {
        while (a >= 25)
        {
            a = a - 25;
            count++;
        }
        while ((a < 25) && (a >= 10))
        {
            a = a - 10;
            count++;
        }
        while ((a < 10) && (a >= 5))
        {
            a = a - 5;
            count++;
        }
        while ((a < 5) && (a >= 1))
        {
            a = a - 1;
            count++;
        }
    } while (a > 0);
    printf ("%d\n", count);
}