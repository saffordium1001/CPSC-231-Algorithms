#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Bin.h"

/**************************************
* Constructor - no parameters
**************************************/
bin::bin()
{
	name = "";
	count = 0;
}

/**************************************
* Get
**************************************/
bool bin::get(istream& in)
{
	in >> name;
	in >> count;
	return in.good();
}

/**************************************
* Put
**************************************/
void bin::put(ostream& out)
{
	out << left;
	out << name;
	out << " ";
	out << count;
	out << " ";
	//commented out - tried to set
	// width for string and integer
	// values display
	//out << setw(12) << name;
	//out << setw(4) << count;
}

/**************************************
* Equal
**************************************/
bool bin::operator == (const bin& b)
{
	return name == b.name;
}


/***************************************
 * Implementation - Operators
 * Safford, Twymun - 23-Sep-2021
**************************************/

/**************************************
* Greater
**************************************/
bool bin::operator > (const bin& b)
{
	return name > b.name;
}
/**************************************
* Lesser
**************************************/
bool bin::operator < (const bin& b)
{
	return name < b.name;
}