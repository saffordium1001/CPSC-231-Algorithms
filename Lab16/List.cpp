/**********************************************
 * List.cpp
 * Created by Twymun Safford
 * CPSC 231-MW
 * Date:10/21/2021
 **********************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "List.h"

/**********************************************
 * Constructor
 **********************************************/
list::list()
{ head = NULL;
}

/**********************************************
 * Destructor
 **********************************************/
list::~list()
{ node *p,*q;

// Check list

  if(head==NULL) return;

// Loop through list

  p = head;
  do { q = p;
       p = p->next;
       delete q;
     } while(p!=head);
}

/*****************************
 * Insert
 *****************************/
bool list::insert(string arg)
{ 
    node *p;

// Create a node
  
  p = new node(arg);
  if(p==NULL) return false;

// Add to empty list

  if(head==NULL)
    { head = current = p;
      p->next = head;
      return true;
    };

// Add at current position

  p->next = current->next;
  current->next = p;
  current = p;
  return true;
}

/*****************************
 * Forward
 *****************************/
void list::forward(ostream& out)
{
    out << "Forwards" << endl;
    out << "--------" << endl;
    // Check list
    if (head != NULL)
    {
        current->forward(out, current);
    }
}

/**********************************************
 * Lab 16
 * Backward Function for List Class
 * Extra Credit
 * Twymun Safford
 * CPSC 231
 * Date:10/21/2021
 **********************************************/
void list::backward(ostream& out)
{
    //print a list backwards
    out << "Backwards" << endl;
    out << "--------" << endl;
    //check list to see if at the end of list
    if (head != NULL)
    {
        //current to backward
        current->backward(out, current);
    }
    
}


/**********************************************
 * Lab 16
 * Rotate Function for List Class
 * Twymun Safford
 * CPSC 231
 * Date:10/21/2021
 **********************************************/
//rotate the current pointer n nodes around the list
void list::rotate(int val)
{
    int i; //counter
    node* p = head;
    for (i = 0; i < val - 1; i++) //user specified value for n nodes
    {
        p = p->next; //rotate from current pointer to next pointer
    }
    current = p; //current pointer after rotations
}

/**********************************************
 * Lab 16
 * Display Function for List Class
 * Twymun Safford
 * CPSC 231
 * Date:10/21/2021
 **********************************************/
//display the node
void list::display(ostream& out)
{
    node* p;
    if (head != NULL) // non-empty list
    {
        p = head; // set p to head
        // loop till we reach the last node of the list
        while (p->next != head)
        {
            p->put(out); // output node p using put function of node class
            p = p->next; // move to the next node
        }
        p->put(out); // output last node
        cout << "\n";
        current->put(out); // output current node
    }
    else // empty list
        out << "Empty list" << endl;
}
