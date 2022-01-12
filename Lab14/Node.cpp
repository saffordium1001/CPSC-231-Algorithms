/**********************************************
 * Node.cpp
 * Created by Safford, Twymun
 * Date: 11-Oct-2021
 *********************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Node.h"

/**********************************************
 * Constructor
 **********************************************/
node::node(string args)
{ name = args;
  next = NULL;
}

/**********************************************
 * Destructor
 **********************************************/
node::~node()
{
	if (next != NULL)
	{
		delete next;
	}
}

/**********************************************
 * Implementation-Recursive Add Function
 * Created by Safford, Twymun
 * Date: 11-Oct-2021
 *********************************************/
//now this is the implemented recursive function
void node::add(node *argp)
{ 
	if (this->next == NULL)
	{
		this->next = argp;
		return;
	}
	//recursively add
	this->next->add(argp);
	//next = argp;
}

/**********************************************
 * Implementation-Node Forwards
 * Created by Safford, Twymun
 * Date: 11-Oct-2021
 *********************************************/
 //now this is the implemented for forwards and needs to be recursive
void node::forwards(ostream& out)
{
	//call to put
	put(out);
	//check if the list is empty
	if (next != NULL)
	{
		//store next value and call forwards
		next->forwards(out);
	}

}

/**********************************************
 * Implementation-Node Backwards
 * Created by Safford, Twymun
 * Date: 11-Oct-2021
 *********************************************/
 //now this is the implemented for backwards and needs to be recursive
void node::backwards(ostream& out)
{
	//check if list is non-empty
	if (next != NULL)
	{
		// reverse current order in linked list
		next->backwards(out);
	}
	//call to put for backwards list
	put(out);

}

/*****************************
 * Output
 *****************************/
void node::put(ostream &out)
{ out << setw(10) << this;
  out << setw(8) << name;
  out << setw(10) << next << endl;
}
