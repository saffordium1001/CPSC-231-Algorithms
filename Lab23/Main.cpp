/************************************
 * Lab23.cpp
 * Twymun K. Safford
 * Last Updated:11/16/2021
 ************************************/
#include <iostream>
#include <fstream>
#include <string>

#define ARRAY_MAX 1000

#include "Heapsort.h"

using namespace std;

void main()
{
	int i, n;

	string fname, name, map[ARRAY_MAX];
	double value, dMap[ARRAY_MAX];
	int data, iMap[ARRAY_MAX];

	fstream in;

	/************************************
	 Test here for strings
	 ************************************/
	 // Initialize
	n = 0;

	// Get file name
	cout << "Enter file name to test strings: ";
	cin >> fname;

	// Read from file
	in.open(fname.data(), ios::in);

	if (!in.is_open())
	{
		return;
	}

	// Loop through file

	while (!in.eof())

	{
		in >> name;

		if (in.good())
		{
			map[n++] = name;
		}

		//if (in.good()) heap_insert(map, n, name);

	};

	// Close file

	in.close();

	// Display array
	cout << endl;
	cout << "Array" << endl << "----------------" << endl;

	for (i = 0; i < n; i++)
	{
		cout << map[i] << " ";
	}
	cout << endl << endl;
	cout << "Heapified Array" << endl << "----------------" << endl;

	// Call heapify
	heapify(map, n);

	for (i = 0; i < n; i++)
	{
		cout << map[i] << " ";
	}
	cout << endl << endl;


	cout << "After Sort" << endl << "----------------" << endl;
	heap_sort(map, n); // sort array in ascending order

	// display array after sort
	for (i = 0; i < n; i++)
	{
		cout << map[i] << " ";
	}

	cout << endl << endl;

	/************************************
	 Test here for integers
	************************************/

	// reset n to 0
	n = 0;

	// Get file name
	cout << "Enter file name to test for integers: ";
	cin >> fname;

	// Read from file
	in.open(fname.data(), ios::in);

	if (!in.is_open()) return;

	// Loop through file

	while (!in.eof())

	{
		in >> data;

		if (in.good()) iMap[n++] = data;

		//if (in.good()) heap_insert(map, n, name);

	};

	// Close file

	in.close();

	// Display array
	cout << endl;
	cout << "Array" << endl << "----------------" << endl;

	for (i = 0; i < n; i++)
	{
		//print the map for integers
		cout << iMap[i] << " ";
	}
	cout << endl << endl;
	cout << "Heapified Array" << endl << "----------------" << endl;

	// Call heapify
	heapify(iMap, n);

	for (i = 0; i < n; i++)
	{
		cout << iMap[i] << " ";
	}
	cout << endl << endl;
	cout << "After Sort" << endl << "----------------" << endl;
	heap_sort(iMap, n); // sort the array in ascending order

	// display array after sort
	for (i = 0; i < n; i++)
	{
		cout << iMap[i] << " ";
	}
	cout << endl << endl;

	/************************************
		 Test here for doubles
	************************************/
	// reset n to 0
	n = 0;

	// Get file name
	cout << "Enter file name to test for doubles: ";
	cin >> fname;

	// Read from file
	in.open(fname.data(), ios::in);

	if (!in.is_open())
	{
		return;
	}

	// Loop through file

	while (!in.eof())
	{
		in >> value;
		if (in.good())
		{
			//print out the map for doubles
			dMap[n++] = value;
		}
		//if (in.good()) heap_insert(map, n, name);
	};

	// Close file

	in.close();

	// Display array
	cout << endl;
	cout << "Array" << endl << "----------------" << endl;

	for (i = 0; i < n; i++)
	{
		cout << dMap[i] << " ";
	}
	cout << endl << endl;
	cout << "Heapified Array" << endl << "----------------" << endl;

	// Call heapify
	heapify(dMap, n);

	for (i = 0; i < n; i++)
	{
		//print out the map for doubles
		cout << dMap[i] << " ";
	}
	cout << endl << endl;
	cout << "After Sort" << endl << "----------------" << endl;
	heap_sort(dMap, n); // sort the array in ascending order

	// display array after sort
	for (i = 0; i < n; i++)
	{
		cout << dMap[i] << " ";
	}

	cout << endl << endl;

	return;
}