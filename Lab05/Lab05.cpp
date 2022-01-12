/*********************************
 * CPSC 231 MW - Lab 05
 * Created by Safford, Twymun
 * Date: 08-Sep-2021
 *********************************/

#include <iostream>
using namespace std;
//for the counter


int linear(int n);
int logarithmic(int n);
int quadratic(int n);

/***************************
 * main()
 ***************************/
void main()
{
	int a, n;

	// Get N

	cout << "Enter N: ";
	cin >> n;

	// Steps 1-4

	//a = linear(n);
	//cout << "Linear count = " << a << endl;


	// Steps 5-8
	//logarithmic count
    //a = logarithmic(n);
	//cout << "Logarithmic count = " << a << endl;



	// Steps 9-12
	//quadratic count
	a = quadratic(n);
	cout << "Quadratic count = " << a << endl;

}



/***************************************
 * linear()
 * Safford, Twymun - 08-Sep-2021
 *
 * Added code additions for exection
 * inside linear loop
**************************************/

/*************************************
int linear(int n)
{
	int i;
	//counter - defined outside of for loop
	int counter;
	float p;
	//initialize counter to zero
	//cout << "Number of Lines | Values" << endl; //debugging
	//cout << "---------------------------" << endl; //debugging
	counter = 0;
	for (i = 0; i < n; i++)
		//n - user defined
		//i will increment until it is
		//no longer less than n
	{
		//cout i and p
		cout << i << " ";
		p = pow(2.718F, i);
		//increment counter by 3
		cout << p << endl;
		counter += 3;
	};
	return counter;
}
*************************************/



/***************************
 * logarithmic()
 * Safford, Twymun - 08-Sep-2021
 *
 * Added code additions for exection
 * inside loop for logarithmic
**************************************/


/*************************************
int logarithmic(int n)
{
	int sum;
	//implement oounter
	int counter;
	//set counter equal to zero
	//sum is equal to 1
	counter = 0;
	sum = 1;
	//integers for i
	//int i;
	//i = 0;
	
		while (sum < n)
		{
			//sum should scale logarithmically
			//cout << i << " ";
			sum = sum * 2;
			//i++;
			//counter - increment by 3
			cout << sum << endl;
			counter += 3;

		};
	return counter;
}
*************************************/




/*************************************
 * quadratic()
* Safford, Twymun - 08-Sep-2021
 *
 * Added code additions for exection
 * inside linear loop
**************************************/
//approximate number of lines of code
//for inner and outer loops
/// n - number of operations



int quadratic(int n)
{
	//i - outer loop for condition
	//j - inner loop for condition
	//m - number of rows for #'s
	int i, j, m;
	//inner - inner operations counter
	//outer - outer operations counter
	int inner, outer;

	// Initialize

	inner = 0;
	outer = 0;

	// Get m

	cout << "Enter M: ";
	cin >> m;

	// Outer loop

	for (i = 0; i < m; i++)
	{

		// Inner loop

		for (j = 0; j < n; j++)
		{
			cout << '#';
			//counter - increment every time inner loop runs
			inner++;
		};
		//increment every time condition for outer loop completes
		outer++;
		//endl for each row of #'s
		cout << endl;
	};
	//cout statement - convey number of outer operations
	cout << "The outer count is = " << outer << endl;
	return inner;
}

