/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

bool binary_search(int value, int values[], int min, int max);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if (n < 1)
    {
        return false;
    }    
    else
    {
        int min = 0;
        int max = n - 1;
        
        return binary_search(value, values, min, max);
    }
}

bool binary_search(int value, int values[], int min, int max)
{
    int mid = (min + max)/2;

    if ((values[min] == value) || (values[max] == value) || (values[mid] == value))
    {
        return true;
    }
    else if (values[mid] < value && min != max)
    {
        return binary_search(value, values, mid + 1, max);
    }
    else if (values[mid] > value && min != max )
    {
        return binary_search(value, values, min, mid - 1);
    } 
    else
    {
        return false;
    }
}

/**
 * Sorts array of n values.
 */
void sort (int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (values[j] < values[min])
            {
                min = j;
            }
        }
        if (min != i)
            {
                int temp = values[min];
                values[min] = values[i];
                values[i] = temp;
            }
    }
    return;
}
