#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int key_diff (int k);

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
        for (int i = 0, n = strlen(key); i < n; i++)
        {
            if(isalpha(key[i]) == false)
            {
                printf("enter a valid key constituting of alphabets only!\n");
                return 1;
            }
        }
        string p = GetString();
        int count = 0;
        int m = strlen(key);
        for (int i = 0, n = strlen(p); i < n; i++)
        {
            if (isalpha(p[i]))
                {
                    int k = (int)key[count % m];
                    count++;
                    int c = (int)p[i] + key_diff(k);
                    if (((int)p[i] > 64) && ((int)p[i] < 91))
                    {
                        if ((c > 64) && (c < 91))
                            {
                                printf ("%c", c);
                            }
                            else if (c >= 91)
                            {
                                c = 'A' + (c - 'Z') - 1;
                                printf ("%c", c);
                            }
                    }
                    else if (((int)p[i] > 96) && ((int)p[i] < 123))
                    {
                        if ((c > 96) && (c < 123))
                            {
                                printf ("%c", c);
                            }
                            else if (c >= 123)
                            {
                                c = 'a' + (c - 'z') - 1;
                                printf ("%c", c);
                            }    
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
}

int key_diff (int k)
{
    int a = 0;
    if ((k > 64) && (k < 91))
    {
        a = k - 65;
    }
    else if ((k > 96) && (k < 123))
    {   
        a = k - 97;
    }
    return a;
}