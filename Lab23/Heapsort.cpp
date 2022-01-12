/************************************
 * Heapsort.cpp
 * Twymun K. Safford
 * Last Updated: 11/16/2021
 ************************************/

#ifndef HEAPSORT_CPP
#define HEAPSORT_CPP

#include "Heapsort.h"

 /************************************
  * Heap Left()
  * Twymun K. Safford
  * Last Updated: 11/16/2021
  ************************************/
  //function to return the index of left child of node at index pos
  //for inserting or removing nodes accordingly
inline int heap_left(int pos)
{
	return 2 * pos + 1;
}

/************************************
 * Heap Right()
 * Twymun K. Safford
 * Last Updated: 11/16/2021
 ************************************/
 // function to return the index of right child of node at index pos
 //for inserting or removing nodes accordingly
inline int heap_right(int pos)
{
	return 2 * pos + 2;
}

/************************************
 * Heap Parent()
 * Twymun K. Safford
 * Last Updated: 11/16/2021
 ************************************/
 // function to return the index of parent child (or parent at root node) of node at index pos
inline int heap_parent(int pos)
{
	return (pos - 1) / 2;
}

/************************************
 * Heap Insert()
 * Twymun K. Safford
 * Last Updated: 11/16/2021
 ************************************/
 // function to insert val into array map to maintain the max heap
 //new node gets compared to parent node, and if larger
 //new value gets swapped with value above
template <typename T> void heap_insert(T map[], int& n, T value)
//void heap_insert(string map[], int& n, string value)
///Now updated to become a template function using the following:
{
	//integers position and parent
	int pos;
	//parent
	int parent;
	map[n] = value; // insert value at the end of map
	pos = n; // set pos to n
	// get the index of parent of pos through call to heap parent
	parent = heap_parent(pos);
	//declare the string variable temp
	//string temp;
	T temp; //changed to template type T
	//at this point, since the new node is larger than its parent node it will be swapped
	while ((pos > 0) && (map[pos] > map[parent]))
	{
		// swap the elements at pos and parent
		temp = map[pos];
		map[pos] = map[parent];
		map[parent] = temp;
		pos = parent; // set pos to parent
		parent = heap_parent(pos); // get the index of parent of pos
	}
	n++; // increment n
}

/************************************
 * Heapify()
 * Twymun K. Safford
 * Last Updated: 11/16/2021
 ************************************/
 //function that takes unorded array and turns it into a heap
 //based on process of heapification - requires heap_insert

// change it to template function
template <typename T> void heapify(T map[], int n)
//void heapify(string map[], int n)
{
	//counter
	int i = 0;
	//while less than size of array, insert elements into heap 
	while (i < n)
	{
		//use heap_insert recursively for tree heapification of the current tree/sub-tree
		heap_insert(map, i, map[i]);
	}
}

/************************************
 * Heap Remove()
 * Twymun K. Safford
 * Last Updated: 11/16/2021
 ************************************/
 //function to remove nodes from a heap
 //starts at root node, moves node at bottom of tree to root,
 // and then another heapification algorithm is used: 
 //current node compared to two children for removal here

// change it to template function
template <typename T> T heap_remove(T map[], int& n)
//string heap_remove(string map[], int& n)
{
	int pos = 0;
	//decrement n by one
	n--;
	//left, right, and index
	int left;
	int right;
	int index;
	//compare ccurrent node to two children and if it isn't 
	//bigger than them, swap with larger of the two
	swap(map[pos], map[n]);
	while (pos < n)
	{
		index = pos;
		left = heap_left(pos);
		right = heap_right(pos);
		//if the left child is larger than the root
		if ((left < n) && (map[left] > map[index]))
		{
			//use the left child as the new index
			index = left;
		}
		//if right child greater than the largest so far
		if ((right < n) && (map[right] > map[index]))
		{
			//use the right child as the index
			index = right;
		}
		//if the largest current value is not at the root
		if (index != pos)
		{
			//then swap the two values
			swap(map[pos], map[index]);
			pos = index;
		}
		else
		{
			//sets position to n
			pos = n;
		}
	}
	return map[n];
}

/************************************
 * Heapsort()
 * Twymun K. Safford
 * Last Updated: 11/16/2021
 ************************************/
//void heap_sort(string map[], int n)
template <typename T> void heap_sort(T map[], int n)
{
	//set int i and set it to 0
	int i = 0;

	//heapify the array to create a max heap (greatest - down to -> lowest)
	//loop while i < n
	while (i < n)
		//call heap_insert(map, i, map[i]);
		heap_insert(map, i, map[i]);

	//now, need to incor
	//sorts the elements based on employing a heapsort - since n decrements by one in heap remove,
	//will run until n is equal to zero
	while (n > 0)
	{
		//calls the heap remove function - removes the max value from map and place at index n-1
		heap_remove(map, n);
	}
}

#endif