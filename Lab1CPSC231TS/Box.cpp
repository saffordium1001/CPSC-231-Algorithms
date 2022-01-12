/***********************************
 * Lab 01.cpp - Box.cpp
 * Written by Twymun Safford  26-Aug-2021
 * CPSC 231MW Fall 2021
 * * w - width
 * * h - height
 ***********************************/

#include <iostream>
using namespace std;
//include the header file "Box.h" that has the box definitions in it
#include "Box.h"
//begin constructors and desctructors for box
/**************************************
 * Constructor - no parameters
 **************************************/
box::box()
{
	cout << "Box " << this << " created\n";
	height = 0;
	width = 0;
}

/**************************************
 * Constructor - all parameters
 **************************************/
box::box(int h, int w)
{
	cout << "Box " << this << " created\n";
	height = h;
	width = w;
}

/**************************************
 * Destructor - optional
 **************************************/
box::~box()
{
	cout << "Box " << this << " destroyed\n";
}

/**************************************
 * Get
 **************************************/
bool box::get(istream& in)
{
	in >> height;
	in >> width;
	return in.good();
}

/**************************************
 * Put Function - Implementation/Solution
 * Safford, Twymun - 24-Aug-2021
 **************************************/
void box::put(ostream& out)
{
	//output for the put function should use
	//height and width - put function
	//was missing for step 3 and needs
	//to be implemented
	cout << height << "x" << width << endl;
}