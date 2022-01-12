/**********************************************
 * Node.cpp
 * Created by Twymun Safford
 * CPSC 231-MW
 * Date:10/21/2021
 **********************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Node.h"

/**********************************************
 * Constructor
 **********************************************/
node::node(string arg)
{ name = arg;
  next = NULL;
}

/*****************************
 * Output
 *****************************/
void node::put(ostream &out)
{ out << setw(10) << this;
  out << setw(8) << name;
  out << setw(10) << next << endl;
}

/**********************************************
 * Lab 16
 * Forward Function for Node Class
 * Twymun Safford
 * CPSC 231
 * Date:10/21/2021
 **********************************************/
void node::forward(ostream& out, node* current)
{
    //display the node, recurse if next pointer
    //is not same as argument pointer
    put(out);
    if (next != NULL && next->name != current->name)
    {
        //print node forward from current pointer
        next->forward(out, current); 
    }
}

/**********************************************
 * Lab 16
 * Extra Credit
 * Backward Function for Node Class
 * Twymun Safford
 * CPSC 231
 * Date:10/21/2021
 **********************************************/
void node::backward(ostream& out, node* current)
{
    //print the list backward of each node, recurse
    //if the next pointer is not same as argument
    //pointer
    if (next != NULL && next->name != current->name)
    {
        next->backward(out, current);
    }
    //display the node (backwards), recurse if next pointer
   //is not same as argument pointer
    put(out);
}