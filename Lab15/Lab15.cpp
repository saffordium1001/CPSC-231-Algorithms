/*********************************
 * Lab 15
 * Created by Safford, Twymun
 * Date: 13-Oct-2021
 *********************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/*********************************
 * main()
 *********************************/
void main()
{
	string s;
	//for individual characters
	string ch;
	fstream infile;
	vector<string> a;
	queue<string> b;
	stack<string> c;
	//for counter
	int i;

	// Open file

	cout << "Enter file name: ";
	cin >> s;
	cout << endl;
	infile.open(s, ios::in);
	if (!infile.is_open()) return;

	// Read data from file
	//Loop - read through file as long as it is not the end of the file
	//display data from input
	cout << "Input: ";
	while (!infile.eof())
	{
		//get characters from contents of list
		infile >> ch;
		cout << ch << " ";
		a.push_back(ch);
	}
	// Close file
	infile.close();

	//display data from vector
	cout << "\nVector: ";

	// Display vector
	for (i = 0; i < a.size(); i++)
	{
		//display the vector - step 3
		cout << a[i] << " ";
	}
	// Copy vector data
	for (i = 0; i < a.size(); i++)
	{
		//comment out if-else statements for step 4, keep b.push(..)
		// uncomment for step 5
		//for stack printing
		if ((i + 1) % 3 == 0)
		{
			c.push(a[i]);
		}
		else
		{

			b.push(a[i]);
		}

	}

	// Display queue

	cout << "\nQueue: ";

	/*1) While loop - check if queue is empty
	  2) If the queue is not empty, print to console the elements of the queue
	 */
	while (!b.empty())
	{
		cout << b.front() << " "; //print queue elements
		//
		b.pop(); //pops that element

	}

	cout << "\nStack: ";

	////// Display stack - every third character
	while (!c.empty())
	{
		cout << c.top() << " ";
		c.pop(); //pop
	//	//make sure it is every third character
	}

}
