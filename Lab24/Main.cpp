/************************************
 * Lab24.cpp
 * Twymun K. Safford
 * Last Updated: 11/17/2021
 ************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#define GRAPH_MAX 10

void display(int n);

string name[GRAPH_MAX] = { "A","B","C","D","E" };
float edge[GRAPH_MAX][GRAPH_MAX] =
{ { -1.00, 2.00, 1.70,-1.00,-1.00 },
  { -1.00,-1.00, 3.50, 1.50,-1.00 },
  { -1.00,-1.00,-1.00, 2.40,-1.00 },
  { -1.00,-1.00,-1.00,-1.00, 4.10 },
  {  9.99,-1.00,-1.00,-1.00,-1.00 }
};

// function to insert new node and edges to the graph 'edge'
void nodeInsert(string node, string from, float edge_weight, int&);

// function to insert new node and edges to the graph 'edge'
//void nodeInsert(string node, string from, float edge_weight);

/******************************
 * main()
 ******************************/
void main()
{
	int i, n;
	int source_index, target_index;
	string s; //source
	string t, node; //target-//new node
	string newNode, target, targetNode; //new node char
	float new_Weight;
	float distance, total;
	//total distance for while loop
	float total_distance;
	bool enterNewNode, doNotQuit;

	// Initialize

	n = 5;
	total_distance = 0;

	// Display

	display(n);
	cout << endl;
	//boolean variable - assess if user wants to enter a new node
	enterNewNode = true;
	//
	do
	{
		cout << "Enter a new node or enter 'Next' to calculate distances: ";
		//input for newNode
		cin >> node;
		if (node == "Next")
		{
			//set boolean variable to false and return
			enterNewNode = false;
			//proceed to calculating target distances based on weights
		}
		else
		{
			enterNewNode = true;
		}
		//new node
		newNode = node[0] - 'A';
		//enter target node to connect to
		cout << "Enter a preexisting node to connect it to: ";
		cin >> targetNode;
		//extract first character for target node
		target = targetNode[0] - 'A';
		//enter new weight for this target
		cout << "Enter the weight for this new edge: ";
		cin >> new_Weight;
		cout << "Now attempting to insert " << node[0] << " to " << targetNode[0] << "with a weight of " << new_Weight << "..." << endl;
		//now, attempt to insert
		nodeInsert(newNode, target, new_Weight, n);
	} while (enterNewNode = true);
	//prompt the user for the source name
	cout << "\nEnter source : ";
	cin >> s;
	//extract the very first character from the input string index and set source_index
	source_index = s[0] - 'A';
	//boolean variable - assess if the user wants to quit
	doNotQuit = true;
	//do this loop as long as doNotQuit is true
	do
	{
		//prompt the user for the target name
		cout << "Enter target : ";
		cin >> t;
		if (t == "Quit")
		{
			//set boolean variable to quit
			doNotQuit = false;
			//quit the program
			return;
		}
		//extract the very first character from the input string index and set as target_index
		target_index = t[0] - 'A';
		//if-else statements to calculate and display the distance between nodes - creates warning if no valid edge

		//if the submitted indices are valid (0 to 5):
		if ((t.length() == 1) && (target_index >= 0) && (target_index < n) && (source_index >= 0) && (source_index < n))
		{
			//no valid edge from the source to the destination
			if (edge[source_index][target_index] < 0) {
				cout << "No edge from " << (char)('A' + source_index) << " to " << (char)('A' + target_index) << endl;
			}
			//if there is a valid distance from the source to the destination along a valid edge, display source to destination
			else
			{
				//calculate the new total distance based on addition of all weights between connected nodes
				total_distance = total_distance + edge[source_index][target_index];
				cout << (char)('A' + source_index) << " to " << (char)('A' + target_index) << " = " << edge[source_index][target_index] << endl;
				//now, the new source becomes the old target and the new target needs to be redefined
				source_index = target_index;
			}
		}
		//if the user has submitted wrong input
		else
		{
			//print out that the user needs to submit valid input
			cout << "Wrong input. Try again" << endl;
		}
		//return statement
	} while (doNotQuit = true);
	return;
}

/******************************
 * display()
 ******************************/
void display(int n)
{
	int i, j;

	// Initialize

	cout << fixed << setprecision(2);

	// Target row

	for (j = 0; j < n; j++)
		cout << setw(7) << name[j];
	cout << endl;

	// Loop through Sources

	for (i = 0; i < n; i++)
	{
		cout << setw(2) << name[i];       // Name
		for (j = 0; j < n; j++)
			cout << setw(7) << edge[i][j];  // Edge distance
		cout << endl;
	};
	return;
}


/******************************
 * node insert
 ******************************/
void nodeInsert(string node, string from, float edge_weight, int& n)
{
	//counters
	int i, j;
	// first check if the weight >= 0
	if (edge_weight < 0)
	{
		return;
	}

	// check if the graph has any space left for adding a new node
	if (n >= GRAPH_MAX)
	{
		cout << "No space left to add a new node.\n";
		return;
	}
	//check to see if the new node and from node are the same
	if (node == from)
	{
		cout << "The new node you tried to enter is the same as an existing node.\n";
		return;
	}
	//check if the new node character already exists as an entry
	for (i = 0; i < n; i++)
	{
		if (node == name[i])
		{
			//tell user current node character already exists
			cout << "The leading character of the node you tried to enter already exists.\n";
			return;
		}
	}

	//int node_index = node[0] - 'A';     // index of new inserting node
	int from_index;
	from_index = from[0] - 'A';     // index of node to which new node is added

   // add the new node to name array and after it, increment the n (from global variable name)
	name[n++] = node[0];

	//2D array 'edge' - insert new edge_weight to the corresonding index.

	//enter -1.00 for other nodes with n already being incremented
	// here "n" is already incremented
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			// for this new row/column, add -1.00
			if (i == (n - 1) || j == (n - 1))
			{
				edge[i][j] = -1.00;
			}

			// now if the current row is "from_edge" and col is new column
			if (i == from_index && j == n - 1)
			{
				edge[i][j] = edge_weight;
			}
			// otherwise leave the previous weight
		}
	}
}