/**********************************************
 * Lab 13
 * Created by Safford, Twymun
 * Date: 06-Oct-2021
 *********************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Node.h"

/**********************************************
 * main()
 **********************************************/
void main()
{
	string name;
	fstream infile;
	node* head, * p, * q;


	//initialize null
	/*head = NULL;*/
	// Open file

	cout << "Enter file name: ";
	cin >> name;
	cout << left << endl;
	infile.open(name, ios::in);

	// Loop through file

	while (!infile.eof())
	{
		infile >> name;
		// Process valid input

		if (infile.good())
		{
			//cout << name << endl;
			//replacement 1
			p = new node(name);
			p->put(cout);
			delete p;
			//replacement 2
		/*	p = new node(name);
			if (head == NULL)
			{
				head = p;
			}
			else
			{
				q->add(p);
			}
			q = p;*/

		};
	};

	// Close file

	infile.close();
	cout << endl;
	// Display
	//p = head;
	//while (p != NULL)
	//{
	//	p->put(cout);
	//	p = p->next;
	//};

	//cout << endl;
	////clean-up - delete the head after no longer needed
	//if (head != NULL)
	//{
	//	delete head;
	//}

}
