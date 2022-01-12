/***********************************
* Node.cpp
 * Written by Twymun K. Safford
 * Last Updated: 11/8/2021
***********************************/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Node.h"

/***********************************
* constructor
***********************************/

node::node(string val)

{
	value = val;
	left = NULL;
	right = NULL;
}

/***********************************
* destructor
***********************************/

node::~node()
{
	// if left value present, delete left value
	if (left != NULL)
	{
		delete left;
	}
	// if left value present, delete left value
	if (right != NULL)
	{
		delete right;
	}
}

/***********************************
* put()
***********************************/

void node::put(ostream& out)
{
	// output the value to given ostream
	out << value << endl;
}

/***********************************
* lmr()
***********************************/
void node::lmr(ostream& out)
{
	if (left != NULL)
	{
		left->lmr(out);
	}
	put(out);
	if (right != NULL)
	{
		right->lmr(out);
	}
}