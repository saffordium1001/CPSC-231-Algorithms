/*********************************
 * Bushel code
 * Created by Mark Bowman
 *********************************/

#include <iostream>
#include <string>
using namespace std;

#include "Bushel.h"

/**************************************
 * Constructor
 **************************************/
bushel::bushel()
{
	int i;
	for (i = 0; i < FRUIT_MAX; i++)
		map[i] = 0;
}

/**************************************
 * get()
 **************************************/
bool bushel::get(istream& in)
{
	int i;
	for (i = 0; i < FRUIT_MAX; i++)
		in >> map[i];
	return(in.good());
}

/**************************************
 * put()
 **************************************/
void bushel::put(ostream& out)
{
	int i;
	for (i = 0; i < FRUIT_MAX; i++)
	{
		out << " " << map[i];
		out << " " << fruit_name[i];
	};
}


/**************************************
 * Operator+ - Implementation/Solution
 * Safford, Twymun - 01-Sep-2021
 *
 * Adds together each of the same type
 * of fruit from bushel A, bushel B,
 *  and yields bushel C as output

* operator+
**************************************/

//creates an operator to add two separate bushels
//into a final third bushel
//header - three different bushels
bushel bushel::operator +(const bushel& b)
{
	// Adding apples, oranges, peaches, pears together
	//bunches (reference to bunches of bananas) is the
	//a bushel needs to be returned - bunches is declared
	bushel bunches;
	//for the bushel bunches:
	int i;
	for (i = 0; i < FRUIT_MAX; i++)
	{
		bunches.map[i] = this->map[i] + b.map[i];
	}
	return bunches;
}

/**************************************
 * Operator- : Implementation/Solution
 * Safford, Twymun - 01-Sep-2021
 *
 * Subtracts each of the same type
 * of fruit from bushel A, bushel B,
 *  and yields bushel C as output
 *
* operator-
**************************************/

//overloaded subtract function
//creates an operator to take the difference
// between the fruits in separate bushels
//and store the remainder into a final third bushel
//header - three different bushels
// need an error checking message for -ve
bushel bushel::operator -(const bushel& b)
{
	// Subtracts the apples, oranges, peaches, pears together
	// If -ve, throw error using cerr
	//bunches - bushel C to be returned
	bushel bunches;

	//we can use a for-loop here - process is the same
	//run all of the fruits in an array and add their quantities
	//if any quantities are less than 0, create cerr and change value
	//to zero for resulting bushel D

	//for the first element i to last one with FRUIT_MAX representing max length of fruit elements
	int i;
	for (i = 0; i < FRUIT_MAX; i++)
	{
		bunches.map[i] = this->map[i] - b.map[i];
		if (bunches.map[i] < 0)
		{
			//produce error statement
			cerr << "There's not enough " << fruit_name[i] << "!" << endl;
			//map this index value to zero
			bunches.map[i] = 0;
		}
	}
	return bunches;
}

