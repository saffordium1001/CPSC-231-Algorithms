/***********************************
* Tree.cpp
 * Written by Twymun K. Safford
 * Last Updated: 11/8/2021
***********************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Tree.h"

/******************************
* Constructor
******************************/
tree::tree()
{
    root = NULL;
}

/******************************
* Destructor
******************************/
tree::~tree()
{
    if (root != NULL)
    {
        delete root;
    }
}

/***********************************
* insert
***********************************/

void tree::insert(string value)
{

    // update the value of root post insertion
    root = inserting(value, root);
}

/***********************************
* node* inserting
***********************************/

node* tree::inserting(string value, node* root)
//helper function that helps with inserting values into tree
{
    node* newNode;
    // if root is null insert the value here
    if (root == NULL)
    {
        newNode = new node(value);
        // Return newNode
        return newNode;
    }
    // if input value is less than root's value, insert in left subtree
    else if (root->value > value)
    {
        root->left = inserting(value, root->left);
    }
    // if input value is greater than root's value, insert in right subtree
    else
    {
        root->right = inserting(value, root->right);
    }
    // return root
    return root;
}

/***********************************
* show()
***********************************/

void tree::show(string order, ostream& out)
{

    // if order is LMR
    if (order == "LMR")
    {

        // display the node in LMR order
        if (root != NULL)
        {
            root->lmr(out);
        }
    }
}

/***********************************
* finding(value, node* root)
***********************************/

bool tree::finding(string value, node* root)
//helper function that assesses if a value exists -> pass to find
{
    // if root is null, the value is not found, return false
    if (root == NULL)
    {
        return false;
    }
    // if the root's value equals input value, return true
    if (root->value == value)
    {
        return true;
    }
    // if input value is less than root's value, search left subtree
    else if (value < root->value)
    {
        return finding(value, root->left);
    }
    // if the input value is more than root's value, search right subtree
    else
    {
        return finding(value, root->right);
    }
}

/***********************************
* find(string value)
***********************************/

bool tree::find(string value)
{
    // return finding value, root
    return finding(value, root);
}

///***********************************
//
//* tree Depth()
//
//***********************************/
//
//int tree::Depth()
//{
//    return findDepth(root) + 1;
//}
//
///***********************************
//
//* findDepth
//
//***********************************/
//
//int tree::findDepth(node* root)
//{
//    if (root == NULL)
//    {
//        return -1;
//    }
//    else
//    {
//        /* compute the depth of each subtree */
//        int lDepth = findDepth(root->left);
//        int rDepth = findDepth(root->right);
//        /* use the larger one */
//        if (lDepth > rDepth)
//        {
//            return (lDepth + 1);
//        }
//        else
//        {
//            return (rDepth + 1);
//        }
//    }
//
//}
//
///***********************************
//
//* tree Count
//
//***********************************/
//
//int tree::Count()
//{
//    return countNode(root);
//}
//
///***********************************
//
//* tree countNode
//
//***********************************/
//
//int tree::countNode(node* root) 
//{
//    //base case
//    if (root == NULL)
//    {
//        return 0;
//    }
//
//    //recursive call to left child and right child and
//     // add the result of these with 1 ( 1 for counting the root)
//    return 1 + countNode(root->left) + countNode(root->right);
//}