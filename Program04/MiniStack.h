/***********************************
* MiniStack.h
* MiniStack Header File
* Created by Safford, Twymun
* Last Updated: 25-Oct-2021
***********************************/

#ifndef MINISTACK_H
#define MINISTACK_H 10 //maximum values that can be in the array

// ministack template
template <class T>
class ministack
{
private:
	T* stackArray; // Pointer to the stack array
	int numOfItems; // number of items in the stack array
public:
	ministack();	//Constructor function
	// ministack operations
	void push(T); //push function
	void pop(); //pop function
	T top(); //top function
	int size(); //size function
};

/***********************************
* Constructor Function
* Created by Safford, Twymun
* Last Updated: 25-Oct-2021
***********************************/
// Constructor
template <class T>
ministack<T>::ministack()
{
	stackArray = new T[MINISTACK_H];
	numOfItems = 0;
}

/***********************************
* Push Function
* Created by Safford, Twymun
* Last Updated: 25-Oct-2021
***********************************/
// pushes the argument onto the stack.
template <class T>
void ministack<T>::push(T item)
{
	// check for overflow
	if (numOfItems >= MINISTACK_H)
	{
		cout << "Stack overflow(no pun intended)!\n";
	}
	else
	{
		// put the value at the end of the array
		stackArray[numOfItems] = item;
		numOfItems++;
		return;
	}
}

/***********************************
* Pop Function
* Created by Safford, Twymun
* Last Updated: 25-Oct-2021
***********************************/
// removes the value at the top of the stack
template <class T>
void ministack<T>::pop()
{
	// check for underflow
	if (numOfItems == 0)
	{
		cout << "Stack underflow!\n";
	}
	else
	{
		// remove the last element
		numOfItems--;
		return;
	}
}

/***********************************
* Top Function
* Created by Safford, Twymun
* Last Updated: 25-Oct-2021
***********************************/
// returns the value at the top of the stack
template <class T>
T ministack<T>::top()
{
	// check for underflow
	if (numOfItems == 0)
	{
		cout << "Stack underflow!\n";
	}
	else
	{
		// return the last element of the stack
		return stackArray[numOfItems - 1];
	}
}

/***********************************
* Size Function
* Created by Safford, Twymun
* Last Updated: 25-Oct-2021
***********************************/
// returns the size of the stack
template <class T>
int ministack<T>::size()
{
	return numOfItems;
}

#endif