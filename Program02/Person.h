/***********************************
 * Person Class Declaration
 * Created by Safford, Twymun
 * Original Date: 08-Sep-2021
 * Update Date: 03-Oct-2021
 *********************************/

//include guards - person.h included multiple times within the file 
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

// change the name of class to person
class person
{
public:
	person();
	bool get(istream& in);
	void put(ostream& out);
	bool operator<(const person& t);
	bool operator>(const person& t);
	bool operator==(int ID); // compare person's ID
	int getAge(); // function to return the age
private:
	string firstName, lastName;
	int age;
	int ID; // add ID
	void capitalize();
};

#endif