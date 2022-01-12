// Tree Functions

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Tree.h"

/****************************
 * tree()
 ****************************/
tree::tree()
{
	int i;
	for (i = 0; i < TREE_MAX; i++)
	{
		map[i] = "";
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
		{
			pos = left(pos);
		}
		else
			pos = right(pos);
	};

	// Fail if past bottom

	if (pos >= TREE_MAX)
	{
		return false;
	}

	// Set node

	map[pos] = s;
	return true;
}

/****************************
 * dump()
 ****************************/
void tree::dump()
{
	int i, n;

	// Get max position

	for (i = 0; i < TREE_MAX; i++)
		if (map[i] > "")
			n = i;
	// Display up to max
	cout << std::left;
	for (i = 0; i <= n; i++)
	{
		cout << setw(4) << i << map[i] << endl;
	}
}

/****************************
 * show()
 ****************************/
void tree::show(string arg)
{
	if (arg == "LMR")
	{
		lmr(0);
	}
	if (arg == "RML")
	{
		rml(0);
	}
	if (arg == "MLR")
	{
		mlr(0);
	}
}

/****************************
 * depth()
 ****************************/
int tree::depth()
{
	return depth_recurse(0);
}

/****************************
 * find()
 * Find Function by Twymun Safford
 * Date Updated: 10-28-2021
 ****************************/
int tree::find(string s)
{
	//find a string in the tree by using binary search - start at root node,
	//traverse each child, and try to find the string/keyword
	int pos = 0; //start at root node
	// Loop between both left and right branches as long as pos is less than tree max
	// or until after checking every node the string is not found
	while ((pos < TREE_MAX) && (map[pos] > ""))
	{
		//if the string is on a branch where the string is less than the current position. go left
		if (s < map[pos])
		{
			pos = left(pos);
		}
		//in the other case that the string is greater than current position check right child or leaf
		else if (s > map[pos])
		{
			pos = right(pos);
		}
		//not found
		else
		{
			return pos;
		}
	};
	// Out of the bounds of tree or not found
	if ((pos >= TREE_MAX) || (map[pos]==""))
	{
		return TREE_ERR;
	}
	//found
	return pos;
}