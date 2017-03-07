#include <stdio.h>
#include <cs50.h>

int main()
{
    int h;
    do
    {
    printf("height: ");
    h = GetInt();
    } while((h < 0) || (h > 23));
    if ((h >= 0) && (h <= 23))
    {
        int loop, space, hash;
        for (loop = 1; loop <= h; loop++)
        {
            for (space = 0; space < (h-loop); space++)
            {   
                printf(" ");
            }
            for (hash = 0; hash < loop; hash++)
            {
                printf("#");
            }
            printf("#");
            printf("\n");
        }
    }
    return 0;
}