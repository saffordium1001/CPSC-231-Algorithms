/*********************************
 * Lab 08
 * Created by Safford, Twymun
 * Date: 21-Sep-2021
 *********************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Bin.h"
#define SIZE 2

/*************************************

* main()

*************************************/

/***************************************
 * Implementation - Double the Array
 * "Size"
 * Safford, Twymun - 21-Sep-2021
 *
 * as input is read in, whenever the number of
 * bins needs  to be increased, the array size
 * is doubled
**************************************/

void main()
{
	//implement int variable size
	int i = 0, len = 0, size = SIZE;
	string fname;
	fstream infile;
	bin* map, * newmap;
	// Initialize
	//size = SIZE;
	// Get memory
	map = new bin[SIZE];
	newmap = new bin[SIZE];
	//map null condition
	if (map == NULL)
	{
		cerr << "Unable to allocate memory" << endl;
		return;
	};

	// Open file
	cout << "Enter file name: ";
	cin >> fname;
	cout << endl;
	infile.open(fname, ios::in);
	if (!infile.is_open())
	{
		return;
	};
	// Loop through file
	while (len < size && !infile.eof())
	{
		//increment length variable
		if (map[len].get(infile))
		{
			len++;
		};
		//should repeat while length is less than size
		if (len >= size)
		{
			//tell user resizing from
			cout << "Resizing from " << size << " to " << 2 * size << endl;
			newmap = new bin[2 * size];
			for (i = 0; i < len; i++)
			{
				newmap[i] = map[i];
			}
			map = newmap;
			size = 2 * size;
		};
	};
	// Close file
	infile.close();
	// Display array
	for (i = 0; i < len + 1; i++)
	{
		map[i].put(cout);
	};
	// Clean up
	delete[] map;

};