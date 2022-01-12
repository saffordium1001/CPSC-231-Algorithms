/***************************************
 * Lab 21
 * Twymun K. Safford
 * Date Updated: 11/11/2021
 ***************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

#define NMAX 1000

int read_array(string fname,float x[],int n);
void bubble_sort(float x[],int n);
void selection_sort(float x[],int n);
void insertion_sort(float x[],int n);

int count_comp,count_swap;

/***************************************
 * main()
 ***************************************/
void main()
{ int i,n;
  float x[NMAX];
  string fname;

// Get user input

  cout << "Enter file name: ";
  cin >> fname;

// Fill array

  n = read_array(fname,x,NMAX);
  cout << n << " values read" << endl;

 //call bubble sort
  //bubble_sort(x, n);
  //call selection sort
  //selection_sort(x, n);
  //call insertion sort
  insertion_sort(x, n);
  cout << "Count compare: " << count_comp << endl;
  cout << "Count swap: " << count_swap << endl;


// Output list

  cout << fixed << setprecision(2);
  for(i=0;i<n;i++)
    cout << setw(10) << x[i];
  cout << endl;
}

/***************************************
 * read_array()
 ***************************************/
int read_array(string fname,float x[],int n)
{ int i;
  fstream f;

// Open file

  f.open(fname,ios::in);
  if(!f.is_open()) return 0;

// Read from file

  i = 0;
  while(i<n && !f.eof())
    { f >> x[i];
      if(f.good()) i++;
    };

// Close and return

  f.close();
  return i;
}

/***************************************
 * bubble_sort()
 ***************************************/
void bubble_sort(float map[], int n)
{
    count_comp = 0;     // initialise to 0
    count_swap = 0;     // initialise to 0
    int i, j;
    float temp;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (n-1); j++) 
        {

            if (map[j] > map[j + 1])
            {
                count_swap++;   // count number of swaps
                temp = map[j];
                map[j] = map[j + 1];
                map[j + 1] = temp;
            }
            count_comp++;       // count number of comparisons
        }
    }
}


/***************************************
 * selection_sort()
 ***************************************/
void selection_sort(float x[],int n)
{ 
    count_comp = 0;     // initialise to 0
    count_swap = 0;     // initialise to 0
    //selection sory function
    int i, j, k;
    float temp;
    //access each element in list
    for (i = 0; i < n; i++)
    {
        //set first element a
        // s minimum on first loop
        //set minimum as next element on next loop
        k = i;
        for (j = i; j < n; j++)
        {

            //compare minimum with each element
            //if greater than next element
            if (x[k] > x[j])
            {
                //set minimum to right adjacent element
                k = j;
            }
            //increment comparison count
            count_comp++;
        }
        //if minimum not in correct place, put minimum in correct place
        if (k != i)
        {
            //swap until in right place
            temp = x[i];
            x[i] = x[k];
            x[k] = temp;
            //increment swap count
            count_swap++;
        }
    }
}


/***************************************
 * insertion_sort()
 ***************************************/
void insertion_sort(float x[],int n)
{ 
    count_comp = 0;     // initialise to 0
    count_swap = 0;     // initialise to 0
    //insertion sort function
    int i, j, pos;
    float temp[NMAX]; //temporary array
    //loop through the map
    for (i = 0; i < n; i++)
    {
        //find insertion position in x
        for (pos = 0; pos < i && temp[pos] < x[i]; pos++);
        count_comp++;
        //shift the rest over by one
        for (j = i; j > pos; j--)
        {
            temp[j] = temp[j - 1];
            count_comp++;
            count_swap++;
        }
        //insert into temp map
        temp[pos] = x[i];
    }
    //copy back into x
    for (i = 0; i < n; i++)
    {
        x[i] = temp[i];
    }
}

