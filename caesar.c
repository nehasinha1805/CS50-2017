#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf ("Enter exactly one command line argument!\n");
        return 1;
    }
    else
    {
        string key = argv[1];
        int k = atoi (key);
        if (k > 0)
        {
            string p = GetString();
            for (int i = 0, n = strlen(p); i < n; i++)
            {
                if (((int)p[i] > 64) && ((int)p[i] < 91))
                {
                    int a = (int)p[i] + (k % 26);
                    if((a > 64) && (a < 91))
                        {
                            printf("%c", a);
                        }
                    else
                        {
                            int b = 'A' + (a - 'Z' - 1);
                            printf("%c", b);
                        }
                }
                else if (((int)p[i] > 96) && ((int)p[i] < 123))
                {
                    int a = (int)p[i] + (k % 26);
                    if((a > 96) && (a < 123))
                        {
                            printf("%c", a);
                        }
                    else
                        {
                            int b = 'a' + (a - 'z' - 1);
                            printf("%c", b);
                        }
                }
                else
                {
                    printf("%c", p[i]);
                }  
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("enter valid key");
            return 0;
        }
    }
}