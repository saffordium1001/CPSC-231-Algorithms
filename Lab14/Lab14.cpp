/**********************************************
 * Lab 14
 * Created by Safford, Twymun
 * Date: 11-Oct-2021
 *********************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Node.h"

/**********************************************
 * main()
 **********************************************/
void main()
{ string name;
  fstream infile;
  node *head,*p,*q;

// Initialize

  head = NULL;

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
        { p = new node(name);
          p->put(cout);
          if (head == NULL)
          {
              head = p;
          }
          else
          {
              //replaced
              head->add(p);
              //q->add(p);
              //q = p;
          }
        };
    };

// Close file

  infile.close();
  cout << endl;

// Display

   p = head;
   while(p!=NULL)
     { //p->put(cout);
       p = p->next;
     };
   //cout << endl;
   cout << "Forwards" << endl;
   if (head != NULL)
   {
       head->forwards(cout);
   }
   cout << endl;
   //print backwards
   cout << "Backwards" << endl;
   if (head != NULL)
   {
       head->backwards(cout);
   }
   cout << endl;


// Clean up

   if (head != NULL)
   {
       delete head;
   }
}