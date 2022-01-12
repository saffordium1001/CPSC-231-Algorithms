/************************************
 * Heapsort.h
 * Twymun K. Safford
 * Last Updated: 11/17/2021
 * For extra credit, implemetnted with
 * templates
 ************************************/

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include <string>
using namespace std;

// Heap sort functions

inline int heap_left(int pos);
inline int heap_right(int pos);
inline int heap_parent(int pos);

//template implementation of heap_inseert
template <typename T> void heap_insert(T map[], int& n, T value);
//void heap_insert(string map[], int& n, string value);

//template implementation of heap remove
template <typename T> T heap_remove(T map[], int& n);
//string heap_remove(string map[], int& n);

//void heapify(string map[], int n);
//template implementation of heapify
template <typename T> void heapify(T map[], int n);

//template implementation of heap_sort
template <typename T> void heap_sort(T map[], int n);
//void heap_sort(string map[], int n);

//include Heapsort.cpp to get the template functions to work
// - the compiler needs to have access to the implementation of the methods
//so implementattion for the templates are separate from declaration
#include "Heapsort.cpp"
#endif // HEAPSORT_H