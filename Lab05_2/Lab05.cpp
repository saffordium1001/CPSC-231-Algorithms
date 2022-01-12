/*********************************
 * Lab 05
 * Created by YOUR NAME HERE
 *********************************/

#include <iostream>
using namespace std;

int linear(int n);
int logarithmic(int n);
int quadratic(int n);

/***************************
 * main()
 ***************************/
void main()
{ int a,n;

// Get N

  cout << "Enter N: ";
  cin >> n;

// Steps 1-4

  a = linear(n);
  cout << "Linear count = " << a << endl;
 
/*
// Steps 5-8

  a = logarithmic(n);
  cout << "Logarithmic count = " << a << endl;
*/
 
/*
// Steps 9-12

  a = quadratic(n);
  cout << "Quadratic count = " << a << endl;
*/
}

/***************************
 * linear()
 ***************************/
int linear(int n)
{ int i;
  float p;

  for(i=0;i<n;i++)
    { cout << i << " ";
      p = pow(2.718F,i);
      cout << p << endl;
    };

  return 0;
}

/***************************
 * logarithmic()
 ***************************/
int logarithmic(int n)
{ int sum;

  sum = 1;

  while(sum<n)
    { sum = sum*2;
      cout << sum << endl;
    };

  return 0;
}

/***************************
 * quadratic()
 ***************************/
int quadratic(int n)
{ int i,j,m;
  int inner,outer;

// Initialize

  inner = outer = 0;

// Get m

  cout << "Enter M: ";
  cin >> m;

// Outer loop

  for(i=0;i<m;i++)
    { 

// Inner loop

      for(j=0;j<n;j++)
        { cout << '#';
        };

    cout << endl;
  };

  return 0;
}
