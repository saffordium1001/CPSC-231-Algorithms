/************************************
 * Lab26.cpp
 * Written by Twymun K. Safford
 * Last Updated: 12/1/2021
 ************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "Node.h"

int find(string name,node map[],int n);

/******************************
 * main()
 ******************************/
void main()
{ int i,n;
  int source_index,target_index,distance;
  string fname,source_name,target_name;
  fstream in;
  bool isTargetPresent, isSourcePresent;
  node map[NODE_MAX];
  node* sourceNode;
  node* targetNode;
  // Initialize
  n = 0;
  i = 0;
  cout << left;

// Get file name

  cout << "Enter file name: ";
  cin >> fname;

// Open file

  in.open(fname,ios::in);

// Loop through file

  while(!in.eof())
    { in >> source_name >> target_name >> distance;
// Add to array 
      if(in.good())
        { 
          isSourcePresent = false;
          isTargetPresent = false;
          //rest i back to zero
          i = 0;
		  while (i < n)
		  {
			  if (map[i].get_value() == source_name)
			  {
				  //if source name is present
				  isSourcePresent = true;
				  //index of source i 
				  source_index = i;
			  }
			  else if (map[i].get_value() == target_name)
			  {
				  // If target is present
				  isTargetPresent = true;
				  // Index of target node
				  target_index = i;
			  }
			  i++;
		  }
		  // Find source
         // Add source if needed
		  if (!isSourcePresent)
		  {
			  //set source index to number of nodes
			  source_index = n;
			  map[n++].set_value(source_name);
		  }
		  // Find target
          // Add target if needed
		  if (!isTargetPresent)
		  {
			  target_index = n;
			  map[n++].set_value(target_name);
		  }
		  // Add to array 

		  //if (in.good())
		  //{
		  //	cout << setw(12) << source_name;
		  //	cout << setw(12) << target_name;
		  //	cout << setw(4) << distance;
		  //	cout << endl;
		  //};
		  sourceNode = &(map[source_index]);
		  targetNode = &(map[target_index]);
		  // Connect
		  sourceNode->connect(targetNode);
        }; 
    };
 
// Close file

  in.close();

// Display array

  for (i = 0; i < n; i++)
  {
	  cout << "\n";
	  map[i].put(cout);
	  cout << "----------------" << endl;
  }

 //Step 5
// Get start

  cout << "Enter start node: ";
  cin >> source_name;

  source_index = find(source_name,map,n);

// Do depth first search

  map[source_index].depth(cout);
  cout << endl;

}

/******************************
 * find()
 ******************************/
int find(string name,node map[],int n)
{ int i;

// Loop through array

for (i = 0; i < n; i++)
{
	if (name == map[i].get_value())
	{
		return i;
	}
}

// Return failure

  return ERR;
}
