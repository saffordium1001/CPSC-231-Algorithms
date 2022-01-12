/***********************************
 * People Class Declaration
 * for container creation
 * Created by Safford, Twymun
 * Date: 03-Oct-2021
 *********************************/

//include guards
#ifndef PEOPLE_H
#define PEOPLE_H

#include "Person.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class people
{
private:
	person* Map;
	int Len;
public:
	people();
	~people();
	void insert(person p);
	void display(ostream& out);
	bool find(int ID);
	void remove(int ID);
};

#endif