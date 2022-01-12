/*********************************
 * Bushel code
 * Created by Mark Bowman
 *********************************/

#include <iostream>
using namespace std;

#include "Bushel.h"

/**************************************
 * Constructor - no parameters
 **************************************/
bushel::bushel()
{
	apples = 0;
	oranges = 0;
}

/**************************************
 * Constructor - all parameters
 **************************************/
bushel::bushel(int a, int o)
{
	apples = a;
	oranges = o;
}

/**************************************
 * get()
 **************************************/
bool bushel::get(istream& in)
{
	in >> apples >> oranges;
	return(in.good());
}

/**************************************
 * put()
 **************************************/
void bushel::put(ostream& out)
{
	out << apples << " Apples ";
	out << oranges << " Oranges";
}

/**************************************
 * equal()
 **************************************/
 /**************************************
 bool bushel::equal(bushel b)
 {
	 if (apples == b.apples && oranges == b.oranges)
		 return true;
	 else
		 return false;
 }
 ***************************************/

 /**************************************
  * Bushel Equal (Operator) - Implementation/Solution
  * Safford, Twymun - 31-Aug-2021
   *Bushel equal operator - should accomplish
   * what the original boolean equal function did
  **************************************/
bool bushel::operator==(bushel b)
{
	// will return true if apples/oranges for bushel A is the same
	// as bushel b
	if (apples == b.apples && oranges == b.oranges)
	{
		return true;
	}
	// will return false otherwise 
	else
	{
		return false;
	}
}

/**************************************
 * Lesser Function Operator - Implementation/Solution
 * Safford, Twymun - 31-Aug-2021
  *Lesser function that should use the logic
  * X has less aplles and X has less oranges
  * than Y; uses boolean operator
 **************************************/

bool bushel::operator<(bushel b)
{
	//if else statement to assess if lesser than
	if (apples < b.apples && oranges < b.oranges)
	{
		//return true if apples and oranges are lesser 
		//than b.apples and b.oranges respectively
		return true;
	}
	else
	{
		//return false if apples > b.apples and oranges > b.oranges
		return false;
	}
}

/**************************************
 * Lesser Function - Implementation/Solution
 * Safford, Twymun - 31-Aug-2021
  *Lesser function that should use the logic
  * X has less aplles and X has less oranges
  * than Y
 **************************************/
 //Boolean - evaluating statements
 //based on comparison between two separate values
/*******************************************
bool bushel::lesser(bushel b)
{
	//if else statement to assess if lesser than
	if (apples < b.apples && oranges < b.oranges)
	{
		//return true if apples and oranges are lesser
		//than b.apples and b.oranges respectively
		return true;
	}
	else
	{
		//return false if apples > b.apples and oranges > b.oranges
		return false;
	}
}
**********************************************/


/**************************************
 * Greater Function Operator - Implementation/Solution
 * Safford, Twymun - 31-Aug-2021
  *greater function that should use the logic
  * X has more aplles and X has more oranges
  * than Y; uses operators instead
 **************************************/

bool bushel::operator>(bushel b)
//Boolean - evaluating statements
//based on comparison between two separate values
{
	//if else statement to assess if greater than
	if (apples > b.apples && oranges > b.oranges)
	{
		//return true if apples and oranges are greater 
		//than b.apples and b.oranges respectively
		return true;
	}
	else
	{
		//return false if apples < b.apples and oranges < b.oranges
		return false;
	}

}

/**************************************
 * Boolean Equal to Operator
 * Implementation/Solution for input
 * Safford, Twymun - 31-Aug-2021
 * not equal operator - compares to 'total'
 * (user input)
 **************************************/
 //boolean operator
bool bushel::operator == (int total)
{
	//if the number of apples and oranges does not equal total
	if (apples + oranges == total)
	{
		//return true
		return true;
	}
	else
	{
		//return false otherwise 
		return false;
	}
}

/**************************************
 * Boolean Not Equal Operator
 * Implementation/Solution for input
 * Safford, Twymun - 31-Aug-2021
 * not equal operator - compares to 'total'
 * (user input)
 **************************************/
//boolean operator
bool bushel::operator!= (int total)
{
	//if the number of apples and oranges does not equal total
	if (apples + oranges != total)
	{
		//return true
		return true;
	}
	else
	{
		//return false otherwise 
		return false;
	}
}

/**************************************
 * Boolean Greater Than Operator
 * Implementation/Solution for input
 * Safford, Twymun - 31-Aug-2021
 * greater than operator - compares to 'total'
 * (user input)
 **************************************/
//boolean operator - is it greater than?
bool bushel::operator > (int total)
{
	//if the total of apples and oranges is greater than the input total
	if (apples + oranges > total)
	{
		//return true
		return true;
	}
	else
	{
		//otherwise return false
		return false;
	}
}

/**************************************
 * Boolean Less Than Operator
 * Implementation/Solution for input
 * Safford, Twymun - 31-Aug-2021
 * less than operator - compares to 'total'
 * (user input)
 **************************************/
 //boolean operator - is it less than?
bool bushel::operator < (int total)
{
	//if the total of apples and oranges is less than the input total
	if (apples + oranges < total)
		//return true
		return true;
	else
		//otherwise, it needs to return false
		return false;
}

/**************************************
 * Greater Function - Implementation/Solution
 * Safford, Twymun - 31-Aug-2021
  *greater function that should use the logic
  * X has more aplles and X has more oranges
  * than Y
 **************************************/
 /*********************************************
 bool bushel::greater(bushel b)
 //Boolean - evaluating statements
 //based on comparison between two separate values
 {
	 //if else statement to assess if greater than
	 if (apples > b.apples && oranges > b.oranges)
	 {
		 //return true if apples and oranges are greater
		 //than b.apples and b.oranges respectively
		 return true;
	 }
	 else
	 {
		 //return false if apples < b.apples and oranges < b.oranges
		 return false;
	 }

 }
 **************************************************/