/**********************************************
 * Node.cpp
 * Created by YOUR NAME HERE
 **********************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Node.h"

/**********************************************
 * Constructor
 **********************************************/
node::node(string args)
{ cerr << this << " Constructed" << endl;
  name = args;
  next = NULL;
}

/**********************************************
 * Destructor
 **********************************************/
node::~node()
{ cerr << this << " Destructed" << endl;
  if(next!=NULL) delete next;
}

/*****************************
 * Add node link
 *****************************/
void node::add(node *argp)
{ next = argp;
}

/*****************************
 * Output
 *****************************/
void node::put(ostream &out)
{ out << setw(10) << this;
  out << setw(8) << name;
  out << setw(10) << next << endl;
}
