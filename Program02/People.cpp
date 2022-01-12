#include "People.h"
#include "Person.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// default constructor
people::people()
{
	// create Map to be an array of size 20
	//inside of the class header 'People.h'
	Map = new person[20];
	//inside of the class header 'People.h'
	Len = 0; // set Len to 0 since it is empty
}

// destructor
people::~people()
{
	delete[] Map;
}

// function to insert p in sorted order
void people::insert(person p)
{
	int i, j;
	if (Len < 20) // check array has space
	{
		// loop to find the index of insertion
		for (i = 0; i < Len; i++)
		{
			if (Map[i] > p) // ith element > p
			{
				// loop to shift the elements right by 1 position from index i to end
				for (j = Len; j > i; j--)
				{
					Map[j] = Map[j - 1];
				}
				// insert p at index i
				Map[i] = p;
				Len++; // increment number of person - up to max size of 20 
				return;
				//break;
			}
		}

		//// insert p at index i
		Map[i] = p;
		Len++; // increment number of person - up to max size of 20 
	}
}

// function to display the details of each person and display average age
void people::display(ostream& out)
{
	int totalAge = 0, avgAge = 0;

	std::cout << std::left << std::setw(10) << "ID" << std::left << std::setw(12) << "Last" << " " 
	<< std::left << std::setw(12) << "First" << std::left << std::setw(12) << "Age" << endl;
	std::cout << std::left << std::setw(10) << "------" << std::left << std::setw(12) << "-------" 
	<< " " << std::left << std::setw(12)
	<< "------" << std::left << std::setw(12) << "------" << endl;
	// loop to display the details of each person and calculate total age of all persons
	int i;
	for (i = 0; i < Len; i++)
	{
		Map[i].put(out);
		totalAge += Map[i].getAge();
	}
	std::cout << std::left << std::setw(10) << "------" << std::left << std::setw(12) << "-------" 
		<< " " << std::left << std::setw(12)
		<< "------" << std::left << std::setw(12) << "------" << endl;
	// calculate average age
	if (Len > 0)
		avgAge = totalAge / Len;

	// display total number of persons and average age
	std::cout << std::left << std::setw(10) << "" << std::left << std::setw(3) << Len 
	<< std::left << std::setw(9) << "Persons" << std::left << std::setw(12) << "Average" 
	<< std::left << std::setw(12) << avgAge << endl;
}

// function to return true if person with ID exists else return false
bool people::find(int ID)
{
	// loop over array
	int i;
	for (i = 0; i < Len; i++)
	{
		if (Map[i] == ID) // person found
			return true;
	}

	return false; // person not found
}

// function to remove the person with ID
void people::remove(int ID)
{
	int i;
	// loop over the array
	for (i = 0; i < Len; i++)
	{
		if (Map[i] == ID) // ID found
		{
			// loop to shift the elements 1 position to left from index i+1 to end
			for (int j = i; j < Len - 1; j++)
				Map[j] = Map[j + 1];
			Len--; // decrement the number of person
			break;
		}
	}
}