/***********************************
* Tree.h
 * Written by Twymun K. Safford
 * Last Updated: 11/8/2021
***********************************/

#ifndef TREE_H
#define TREE_H
//#include <string>
//#include <fstream>
#include "Node.h"
class tree

{
public:
	tree();                                          // public tree constructor
	~tree();                                         // public ~tree deconstructor
	void insert(string value);                      // public insert
	void show(string order, ostream& out);          // public show
	bool find(string value);                        // public find
	//int Depth();                                     //  public Depth
	//int Count();                                      //  public Count
private:
	node* root;                                      // private node* root
	bool finding(string value, node* root);         // private bool finding
	node* inserting(string value, node* root);      // private node* inserting
	//int findDepth(node* root);  //  private int findDepth
	//int countNode(node* root);  //  private int countNode
};

#endif
