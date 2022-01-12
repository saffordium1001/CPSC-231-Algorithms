/************************************
 * Lab27.cpp
 * Written by Twymun K. Safford
 ************************************/
#include <iostream>
#include <string>
using namespace std;

#include "Lab27.h2"

/******************************
 * main()
 ******************************/
void main()
{
 //start - starting city from user selection
 //stop - end city from user selection
 //pos- current position
 // i - counter for city list
 //temp - second index counter to seatch through all elements of 2d array for cities
	int pos, temp, start, stop;
	int i;
	//total distance travelled
	int total = 0;
	//print statement for the city list with index
	std::cout << "City List\n--------------------" << endl;
	for (i = 0; i < CITY_MAX; i++)
	{
		std::cout << i << ") " << city[i] << endl;
	}
	//ask user to input start city
	std::cout << "\nEnter the index of the starting city: ";
	cin >> start;
	//ask user to enter output city
	std::cout << "Enter the index of the stop city: ";
	cin >> stop;
	//set pos equal to start and temp to 0
	pos = start;
	//integer array - determine if a city has been visited yet or not
	int vis[CITY_MAX] = { 0 };
	// starting city is always visited
	vis[start] = 1;
	//set temp to 0
	temp = 0;
	//iterate until start does not equal the end
	while (pos != stop && pos < CITY_MAX)// && pos < CITY_MAX)
	{
			// map[i][temp] != 0 as well as the destination city is not visited
		if ((map[pos][temp] != 0) && (vis[temp] == 0))
		{
			std::cout << city[pos] << " to " << city[temp] << " = " << map[pos][temp] << endl;
			//add the weight for each leg of the trip to the total
			total += map[pos][temp];
			//mark that element in the row as invalid
			map[pos][temp] = 0;
			//mark that city as visited
			vis[temp] = 1;
			//set pos equal to temp since it is the new position
			pos = temp;
			//increment temp - needs to happen in both cases even if the initial weight was not zero
			temp++;
		}
		//criteria to get stuck in a city
		//else
		//{
		//	cout << "Looks like we got stuck here. Can't make it to " << city[stop] << endl;
		//	return;
		//}
		//else, increment temp and visit the other necessary cities along the way since
		//a city/current city has already been visited
		else
		{
			temp++;
		}
	}
	std::cout << "\nTotal distance = " << total;
}


