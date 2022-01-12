/**********************************************
 * Lab 09
 * Created by Safford, Twymun
 * Date: 23-Sep-2021
 *********************************/
#include <iostream>
#include <string>
#include "Bin.cpp"
using namespace std;


/***************************************
 * Implementation
 * Template Function
 * Safford, Twymun - 23-Sep-2021
 *
 * template function called mini_sort() that 
 * takes three arguments, all the same data type, 
 * and arranges them in ascending order
**************************************/


template<class T> void mini_sort(T& x, T& y, T& z)
{
    T temp;
    //Checks and swaps the first two objects in ascending order
    if (x > y) 
    {
        temp = x;
        x = y;
        y = temp;
    };
    //Checks and swaps the second and third objects in ascending order
    if (y > z)
    {
        temp = y;
        y = z;
        z = temp;
    };
    //Again checks and swaps the first two objects in ascending order
    if (x > y) 
    {
        temp = x;
        x = y;
        y = temp;
    };

};

 void main()
{ 
  int i = 0,j = 0,k=0;
  string a,b,c;

// Get 1st user entry

  cout << "Enter three integers: ";
  cin >> i >> j >> k;

// Mini-sort

  mini_sort(i,j,k);

// Display

  cout << i << " < ";
  cout << j << " < ";
  cout << k << endl << endl;

// Get 2nd user entry

  cout << "Enter three names: ";
  cin >> a >> b >> c;


  /***********************************************************
 * Implementation
 * Mini-Sort function
 * Safford, Twymun - 23-Sep-2021
 *
 function called mini_sort() that
 * takes three arguments with a combination of
 * string and integer value (as part of a bin) and sorts
 * them in acending order by string, and then by
 * integer values
**************************************************************/

// Mini-sort

  mini_sort(a,b,c);

// Display

  cout << a << " < ";
  cout << b << " < ";
  cout << c << endl << endl;
  //Get 3 Bins entry

  //bin 1 entry
  cout << "Enter bin 1:";
  bin bin1;
  bin1.get(cin);


  //bin 2 entry
  cout << "Enter bin 2:";
  bin bin2;
  bin2.get(cin);


  //bin 3 entry
  cout << "Enter bin 3:";
  bin bin3;
  bin3.get(cin);

  //call minisort function
  mini_sort(bin1, bin2, bin3);


  //output
  bin1.put(cout);
  cout << "< ";

  bin2.put(cout);
  cout << "< ";

  bin3.put(cout);

  return;
 }
