/**********************************************
 * Lab 16
 * Created by Mark M Bowman
 **********************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "List.h"

/**********************************************
 * main()
 **********************************************/
void main()
{ int n;
  string name;
  fstream infile;
  list a;

// Open file

  cout << "Enter file name: ";
  cin >> name;
  cout << left << endl;
  infile.open(name,ios::in);

// Loop through file

  while(!infile.eof())
    { infile >> name;

// Process valid input

      if(infile.good())
        a.insert(name);
    };

// Close file

  infile.close();

//Step 7

  cout << "Enter rotations: ";
  cin >> n;
  cout << endl;
  a.rotate(n);

 //Step 3

  a.display(cout);
  cout << endl;

//Step 10

  a.forward(cout);
  cout << endl;
 
//Extra credit - backwards
   a.backward(cout);
   cout << endl;

}