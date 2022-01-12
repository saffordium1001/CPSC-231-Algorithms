/**********************************************
 * Lab 19
 * Written by Mark M Bowman
 **********************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Tree.h"

void read_file(tree &t);

/**********************************************
 * main
 **********************************************/
void main()
{ string fname,s;
  fstream infile;
  tree a,b,c;

// Read into trees

  read_file(a);  a.show("Dump");
  read_file(b);  b.show("Dump");

// Add trees

  c = a+b;

// Display tree in order

  cout << "Enter display order (Dump,LMR,RML,MLR): ";
  cin >> s;

  c.show(s);
  cout << endl;

// Depth

  cout << "Depth = " << c.depth() << endl;
}

/**********************************************
 * main
 **********************************************/
void read_file(tree &t)
{ string fname,s;
  fstream infile;

// Open file

  cout << "Enter file name:  ";
  cin >> fname;
  infile.open(fname.data(),ios::in);

// Loop through file

  while(!infile.eof())
    { infile >> s;
      if(infile.good()) t.insert(s);
    };

// Close file

  infile.close();
}
