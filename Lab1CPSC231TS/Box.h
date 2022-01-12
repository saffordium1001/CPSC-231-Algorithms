/***********************************
 * Lab 01.cpp - Box.h
 * Box class definition header file
 * Written by Twymun Safford  26-Aug-2021
 * CPSC 231MW Fall 2021
 ***********************************/

 // Box class definition

class box
{
public:
	box();                      // Constructor - null
	box(int, int);               // Constructor - parameters
	~box();                     // Destructor
	bool get(istream& in);      // Input dimensions
	void put(ostream& out);     // Output dimensions
	int  area();                // Calculate area - area should be length * width (not implemented yet)
	int  perimeter();           // Calculate perimeter - perimeter should be 2 * length + 2 * width for a box (not implemented yet)
private:
	int height, width;           // Dimensions of the box - no units specified
};
