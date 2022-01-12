/************************************
 * Lab25.cpp
 * Written by Twymun Safford
 * Date Updated: 11/29/2021
 ************************************/
#include <iostream>
#include <string>
using namespace std;
#include "Node.h"

/******************************
 * Null constructor
 ******************************/
node::node()
{
	int i;
	value = "";
	for (i = 0; i < EDGE_MAX; i++)
		edge[i] = NULL;
}

/******************************
 * set_value()
 ******************************/
void node::set_value(string arg)
{
	value = arg;
}

/******************************
 * get_value()
 ******************************/
string node::get_value()
{
	return value;
}

/******************************
 * connect()
 ******************************/
void node::connect(node* otherNodes)
//function to connect one node to another
{
	//number of edges, existing index, and existing node
	int numberOfEdges, existingIndex, existingNode;
	numberOfEdges = 0;
	existingIndex = 0;
	existingNode = 0;
	//counter variable
	int i = 0;
	cout << "Now connecting " << otherNodes->get_value() << " to " << get_value() << endl;
	//search for the position which is empty in edge array of the node - search all elements of array edge
	bool found;
	found = false;
	//search through all while the edge is not null
	while (edge[i] != NULL)
	{
		if (edge[i] == otherNodes)
		{
			//if existing node is found, set index to i
			found = true;
			existingIndex = i;
		}
		//incrmeent by i 
		i++;
	}
	//set number of edges equal to i
	numberOfEdges = i;
	if (!found)
	{
		//if not found, the number of edges will be equal to the edges shared by the other node
		edge[numberOfEdges] = otherNodes;
	}
	else
	{
		//if found, set the value of the edge for that index in array
		//equal to the value of the edge for that index in the existing index
		edge[numberOfEdges] = edge[existingIndex];
	}
}

/******************************
 * put()
 ******************************/
void node::put(ostream&)
//output function-displays the node's value followed by values of node's immediate neighbors
{
	//counter integer
	int i = 0;
	//print statement
	cout << get_value() << endl;
	//need to put in while loop to print all edges of the node until NULL
	while (edge[i] != NULL)
	{
		cout << "---" << edge[i]->get_value() << endl;
		i++;
	}
}