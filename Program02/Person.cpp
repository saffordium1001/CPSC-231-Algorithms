/***********************************
 * Person Class Definitions
 * Created by Safford, Twymun
 * Date: 08-Sep-2021
 * Update Date: 03-Oct-2021
 *********************************/

#include "Person.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include <cctype>



/**********************************
 * Null constructor
 **********************************/
person::person() :firstName(""), lastName(""), age()
{
	//null constructor - empty
}

/**************************************
 * get() - Read first name, last name,
 * and age from I/O stream (updated to
 * use Boolean versus the void used
 * in Program 01)
 **************************************/

 // function to read first name, last name, and age from an input stream
 //void person::get(istream &in)
bool person::get(istream& in)
{
	if (in.eof())
	{
		return false;
	}
	in >> ID >> firstName >> lastName >> age;
	capitalize(); // helper function to capitalize the first and last name
	return true;
}


/*************************************
* Capitalize - function to capitalize
* first and last names.
* Updated 04-Oct-2021
*************************************/
// helper function to capitalize the first and last names
void person::capitalize()
{
	//unsigned integer size_t
	size_t i;
	//temp - used to temporarily hold first/last name before capitalizing 
	string temp = "";
	// capitalize the first name i.e first letter will be capital and rest small
	for (i = 0; i < firstName.length(); i++)
	{
		if (i == 0)
			temp += toupper(firstName[i]);
		else
			temp += tolower(firstName[i]);
	}
	//update their first name
	firstName = temp;

	// capitalize the last name i.e first letter will be capital and rest small
	temp = "";
	for (i = 0; i < lastName.length(); i++)
	{
		if (i == 0)
			temp += toupper(lastName[i]);
		else
			temp += tolower(lastName[i]);
	}

	lastName = temp; // update lastName
}



/**************************************
 * put() - writes last name, first name,
 * and age to an output stream (to screen
 * in this case)
 * *Updated 04-Oct-2021 for spacing
 **************************************/

 // function to write last name, first name, and age to an output stream
void person::put(ostream& out)
{
	std::cout << std::left << std::setw(10) << ID << std::left << std::setw(12)
		<< lastName << " " << std::left << std::setw(12) << firstName << std::left
		<< std::setw(12) << age << endl;
}


/**************************************
 * Comparison Operators : Implementation/Solution
 * Safford, Twymun - 08-Sep-2021
 *
 * >, <, and == - to compare the person
 * to another person: uses last name, then
 * first name, and then age - returns
 * boolean
 *
 * i.e.:
 *
 * Mark Bowman 20
 * Frank Bowman 40
 * Frank Bowman 16
 *
 * would be:
 *
 * Bowman Frank 16
 * Bowman Frank 40
 * Bowman Mark 20
 *
 * Updated for Program 2: 04-Oct-2021
 * to compare IDs now
**************************************/


/**************************************
 * Operator : <
 * Safford, Twymun - 08-Sep-2021
**************************************/


// function to compare this trial with t and return true if this trial < p else return false
bool person::operator<(const person& p)
{
	// trials are compared using last name, first name and then age
	return (lastName < p.lastName) || (lastName == p.lastName && firstName < p.firstName)
		|| (lastName == p.lastName && firstName == p.firstName && age < p.age);
}

/**************************************
 * Operator : >
 * Safford, Twymun - 08-Sep-2021
**************************************/

// function to compare this trial with t and return true if this trial > p else return false
bool person:: operator>(const person& p)
{
	return (lastName > p.lastName) || (lastName == p.lastName && firstName > p.firstName)
		|| (lastName == p.lastName && firstName == p.firstName && age > p.age);
}

///**************************************
// * Operator : ==
// * Safford, Twymun - 08-Sep-2021
//**************************************/
//
//// function to compare this trial with t and return true if this trial = p else return false
//bool person:: operator==(const person& p)
//{
//	return (lastName == p.lastName && firstName == p.firstName && age == p.age);
//}

/*************************************
* Implementation - Operator: == (updated)
* the individual with the int ID
* Implemented: 04-Oct-2021
*************************************/
bool person:: operator==(int ID)
{
	return (this->ID == ID);
}

/****************************
function to return the age of
the individual
*Implemented: 04-Oct-2021
*****************************/
int person::getAge()
{
	return age;
}