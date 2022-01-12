/**********************************************
 * Search & Sort.cpp
 * Your name goes here
 **********************************************/

#include <iostream>
#include <string>
using namespace std;

#define ARRAY_MAX  10000
#define NOT_FOUND  -1

extern long counter;

/**********************************************
 * linear() - RUNS PAST
 **********************************************/
int linear(string map[], string item, int n)
{
    for (int i = 0; i < n; i++)
    {
        counter++;
        if (map[i] == item)
            return i;
        if (map[i] > item)
            return NOT_FOUND;
    }
    return NOT_FOUND;
}


/**********************************************
 * binary()
 **********************************************/
int binary(string map[], string item, int n)
{
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        counter++; //counter
        int m = (l + r) / 2;// 0 5 => 2 //// 3 5 => 4

        // Check if item is present at mid
        if (map[m] == item)
        {
            return m;
        }

        // If item greater, ignore left half   1 2 3 4 5    => 4
        if (map[m] < item)
        {
            l = m + 1;
        }

        // If x is smaller, ignore right half
        else
        {
            r = m - 1;
        }
    }

    return NOT_FOUND;
}

/**********************************************
 * sort()
 **********************************************/
void sort(string map[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (map[j] > map[j + 1])
            {
                string temp = map[j];
                map[j] = map[j + 1];
                map[j + 1] = temp;
            }
        }
    }
}

