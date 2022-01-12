/*********************************
 * Bushel header
 * Created by Mark Bowman
 *********************************/

#include <iostream>
using namespace std;

class bushel
{
public:
	bushel();                  // Constructor - empty
	bushel(int, int);           // Constructor with counts
	bool get(istream&);       // Input
	void put(ostream&);       // Output
	//bool equal(bushel);        // Compare to another bushel
	/**************************************
	* Bushel Equal Operator - Implementation/Solution
	* Safford, Twymun - 31-Aug-2021
	* Converts it to bool operator
	**************************************/
	bool operator == (bushel); // Compare to another bushel
	/**************************************
	* Bushel Comparison Operator - Implementation/Solution
	* Safford, Twymun - 31-Aug-2021
	* Converts comparison statements to bool operator statements
	**************************************/
	bool operator > (bushel); // compare greater than for bushel
	bool operator < (bushel); //comare less than for bushel
	//bool lesser(bushel);      //evaluate if bushel is lesser than
	//bool greater(bushel);     //evaluate if bushel is greater than
	/**************************************
	* Bushel Comparison Operator for Int.
	* Implementation/Solution
	* Safford, Twymun - 31-Aug-2021
	* Converts comparison statements to bool operator statements
	* Compares to user input value
	**************************************/
	bool operator == (int); //is equal to comparison - user input integer
	bool operator != (int); //not comparison - user input integer
	bool operator > (int); //greater than user integer
	bool operator < (int); //less than user integer
private:
	int apples;                // Apples in bushel
	int oranges;               // Oranges in bushel 
};
