/***********************************
* MiniQueue.h
* MiniQueue Header File
* Created by Safford, Twymun
* Last Updated: 25-Oct-2021
***********************************/
#ifndef MINIQUEUE_H
#define MINIQUEUE_H 10

// MiniQueue template
template <class T>
class miniqueue
{
private:
	T* queueArray; // Pointer to the queue array
	int numOfItems; // Number of items in the queue
public:
	// Constructor
	miniqueue(); //Constructor function
	// miniqueue operations
	void push(T item); //push function
	void pop(); //pop function
	T front(); //front function
	int size(); //size function
};

/***********************************
* Constructor Function
* Created by Safford, Twymun
* Last Updated: 25-Oct-2021
***********************************/
// This constructor creates an empty queue
template <class T>
miniqueue<T>::miniqueue()
{
	queueArray = new T[MINIQUEUE_H];
	numOfItems = 0;
}
/***********************************
* Push Function
* Created by Safford, Twymun
* Last Updated: 25-Oct-2021
***********************************/
// inserts a value at the end of the queue.
template <class T>
void miniqueue<T>::push(T item)
{
	// check for overflow
	if (numOfItems >= MINIQUEUE_H)
	{
		cout << "Queue overflow!\n";
	}
	else
	{
		// Insert new item
		queueArray[numOfItems] = item;
		// Update item count
		numOfItems++;
		return;
	}
}
/***********************************
* Pop Function
* Created by Safford, Twymun
* Last Updated: 25-Oct-2021
***********************************/
// removes the value at the start of the queue
template <class T>
void miniqueue<T>::pop()
{
	int i = 0;
	// check for underflow
	if (numOfItems == 0)
		cout << "Queue underflow!\n";
	else
	{
		// shift the array by 1 position to left to remove the first element
		for (i; i < (numOfItems - 1); i++)
		{
			queueArray[i] = queueArray[i + 1];
		}
		// Update item count
		numOfItems--;
		return;
	}
}
/***********************************
* Front Function
* Created by Safford, Twymun
* Last Updated: 25-Oct-2021
***********************************/
// returns the front element of the queue
template <class T>
T miniqueue<T>::front()
{
	// check for underflow
	if (numOfItems == 0)
	{
		cout << "Queue underflow!\n";
	}
	else
	{
		return queueArray[0];
	}
}
/***********************************
* Size Function
* Created by Safford, Twymun
* Last Updated: 25-Oct-2021
***********************************/
// returns the current size of the queue
template <class T>
int miniqueue<T>::size()
{
	return numOfItems;
}

#endif