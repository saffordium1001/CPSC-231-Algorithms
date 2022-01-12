// Tree Functions

#include <iostream>
#include <string>
using namespace std;

#include "Tree.h"

/****************************
 * tree()
 ****************************/
tree::tree()
{
	int i;
	for (i = 0; i < TREE_MAX; i++) map[i] = "";
}


/**************************************
 * Copy Constructor by Twymun Safford
 * Date Updated: 11-05-2021
 **************************************/
/* desired copy constructor */
tree::tree(const tree& t) 
{
	int i;
	for (i = 0; i < TREE_MAX; i++)
	{
		map[i] = t.map[i];
	} 
}
/****************************
 * insert()
 ****************************/
bool tree::insert(string s)
{
	int pos;

	// Start at root

	pos = 0;

	// Loop left/right

	while (pos < TREE_MAX && map[pos] != "")
	{
		if (s <= map[pos])
			pos = left(pos);
		else
			pos = right(pos);
	};

	// Fail if past bottom

	if (pos >= TREE_MAX) return false;

	// Set node

	map[pos] = s;
	return true;
}

/****************************
 * show()
 ****************************/
void tree::show(string arg)
{
	if (arg[0] == 'D') dump();
	if (arg == "LMR") lmr(0);
	if (arg == "RML") rml(0);
	if (arg == "MLR") mlr(0);
}

/**************************************
 * addition
 * Addition Operator by Twymun Safford
 * Date Updated: 11-02-2021
 **************************************/
tree tree::operator+(const tree& t)
{
	int i;
	//add two trees
	//declare local tree temp
	tree temp;
	//loop - copies valid elements from
	//current tree map into temp map
	for (i = 0; i < TREE_MAX; i++)
	{
		if (map[i] != "")
		{
			temp.insert(map[i]);
		}
	}
	//put valid elements into temp using insert
	for (i = 0; i < TREE_MAX; i++) 
	{
		if (t.map[i] != "")
			temp.insert(t.map[i]);
	}
	//return temp
	return temp;
}


/**************************************
 * equal
 * Equal Operator by Twymun Safford
 * Date Updated: 11-05-2021
 **************************************/

void tree::operator=(const tree& t) 
{
	int i;
	for (i = 0; i < TREE_MAX; i++)
	{
		map[i] = t.map[i];
	}
}


/****************************
 * depth()
 ****************************/
int tree::depth()
{
	return depth(0) - 1;
}

