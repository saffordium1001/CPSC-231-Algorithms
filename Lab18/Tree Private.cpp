// Tree Functions

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include "Tree.h"

/****************************
 * left()
 ****************************/
int tree::left(int pos)
{
	return pos * 2 + 1;
}

/****************************
 * right()
 ****************************/
int tree::right(int pos)
{
	return (pos + 1) * 2;
}

/****************************
 * depth()
 ****************************/
int tree::depth_recurse(int pos)
{
	int l, r;

	// Return if bottom or empty node

	if (pos >= TREE_MAX)
	{
		return 0;
	}
	if (map[pos] == "")
	{
		return 0;
	}

	// Left,Right

	l = depth_recurse(left(pos));
	r = depth_recurse(right(pos));

	// Max of both sides + middle

	return max(l, r) + 1;
}

/****************************
 * lmr()
 ****************************/
void tree::lmr(int pos)
{
/***************************************
*LMR Implementation
* Twymun Safford
* Date Updated: 10-28-2021
***************************************/
	//check if outside of tree depth or empty and return if so
	if (pos >= TREE_MAX || map[pos] == "")
	{
		return;
	}
	//call recursively for left child branch and lower as it works its way up from bottom node to root
	lmr(left(pos));
	//print (in order) results of LMR binary search
	cout << map[pos] << endl;
	//call resursively for right child branch and down
	lmr(right(pos));
	
}
/****************************
 * rml()
 * RML Implementation by Twymun Safford
 * Date Updated: 10-28-2021
 ****************************/
void tree::rml(int pos)
{
	//check if outside of tree depth or empty and return if so
	if (pos >= TREE_MAX || map[pos] == "")
	{
		return;
	}
	//call recursively for right child branch and lower as it works its way up from bottom node to root
	rml(right(pos));
	//print (in order) results of RML binary search
	cout << map[pos] << endl;
	//call recursively for left child branch and lower as it works its way up from bottom node to root
	rml(left(pos));
	
}
/****************************
 * mlr()
 * MLR Implementation by Twymun Safford
 * Date Updated: 10-28-2021
 ****************************/
void tree::mlr(int pos)
{
	//outputs the current node first, then the two children (pre-order)
	//check if outside of tree depth or empty and return if so
	if (pos >= TREE_MAX || map[pos] == "")
	{
		return;
	}
	//print (in order) results of LMR binary search
	cout << map[pos] << endl;
	//call recursively for left child branch and lower as it works its way up from bottom node to root
	mlr(left(pos));
	//call recursively for right child branch and lower as it works its way up from bottom node to root
	mlr(right(pos));
	
}