/*********************************
 * Lab 28
 * Created by Twymun K. Safford
 *********************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

#define TABLE_MAX  21

#include "Node.h"

int hash_insert(node* table[], node* p, int id);

/*********************************
 * main()
 *********************************/
void main()
{
	int i, id, count;
	string fname, first, last;
	fstream infile;
	node* table[TABLE_MAX], * p;

	// Initialize

	for (i = 0; i < TABLE_MAX; i++)
		table[i] = NULL;
	count = 0;

	// Open file

	cout << "Enter file name: ";
	cin >> fname;
	infile.open(fname.data(), ios::in);
	if (!infile.is_open()) return;

	// Read data from file

	while (!infile.eof())
	{
		infile >> id >> first >> last;

		// Process if input is valid
		//assign p to values
		//node* p = new node(id, first, last);
		p = new node(id, first, last);

		if (infile.good())
		{
			//call the hash insert function
			count += hash_insert(table, p, id);
		};
	};

	// Close file

	infile.close();

	// Display table

	cout << endl;
	for (i = 0; i < TABLE_MAX; i++)
	{
		cout << left << setw(4) << i;
		if (table[i] != NULL) table[i]->put(cout);
		cout << endl;
	};

	// Collisions

	cout << endl;
	cout << "Collisions: " << count << endl;

	// Clean up

	for (i = 0; i < TABLE_MAX; i++)
		if (table[i] != NULL) delete table[i];
}

int hash_insert(node* table[], node* p, int id)
{
	//to store collisions
	int collisions = 0;
	//hash insert function to insert an element in side the table
	//first compute the hashIndex
	int index = (id * 215 + 37) % 21;

	//check if the index location is empty
	if (table[index] == NULL)
	{
		table[index] = p;
	}
	//if location is not empty use linear hashing
	//in linear hashing we move forward till we find an empty location where data can be inserted
	else
	{
		int cur = index;
		cur = (cur + 1) % TABLE_MAX; //move cur forward
		//move until back to  same location as started
		collisions = 1; //collison is 1 as already one collision has occured
		while (cur != index)
		{
			//if empty location found insert the value
			if (table[cur] == NULL)
			{
				table[cur] = p;
				//return the number of collisions
				return collisions;
			}
			else //if not an empty location increment cur and number of colisions
			{
				cur = (cur + 1) % TABLE_MAX;
				collisions += 1;
			}
		}
	}
	return collisions; //return final collisions if no location found
}