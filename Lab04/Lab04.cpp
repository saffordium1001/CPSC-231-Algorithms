/******************************************
 * Lab 04 - Main function
 * Created by Twymun Safford  01-Sep-2021
 * CPSC 231MW Fall 2021
 *****************************************/

#include <iostream>
using namespace std;

#include "Bushel.h"

/***********************************
 * main()
 ***********************************/
void main()
{ class bushel a,b,c,d;

// Get bushels

  cout << "Enter bushel A: ";
  a.get(cin);
  cout << "Enter bushel B: ";
  b.get(cin);

// Output bushels

  cout << "A: ";
  a.put(cout);
  cout << endl;
  
  cout << "B: ";
  b.put(cout);
  cout << endl;
  
// Step 4
// Do addition

  c = a+b;

// Output

  cout << "C: ";
  c.put(cout);
  cout << endl;
  

// Step 4
// Subtraction

  d = a-b;

// Output

  cout << "D: ";
  d.put(cout);
  cout << endl;
  
}