/***********************************
* Node.h
 * Written by Twymun K. Safford
 * Last Updated: 11/8/2021
***********************************/

#ifndef NODE_H
#define NODE_H
//#include <string>
//#include <fstream>
//using namespace std;
class tree;
class node
{
    friend tree;                   // declare tree as a friend class to node class
public:
    node(string val);            // public node(string val) constructor
    ~node();                     // public ~node() deconstructor
    void put(ostream& out);      // void put(ostream& out)
    void lmr(ostream& out);      // void lmr(ostream& out)
private:
    string value;                // private string value
    node* left;                  // private node* left
    node* right;                 // private node* right
};

typedef node* node_ptr;
#endif
