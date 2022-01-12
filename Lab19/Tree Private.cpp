// Tree Functions

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

#include "Tree.h"

/****************************
 * dump()
 ****************************/
void tree::dump()
{ int i,n;

// Get max position

  n = 0;
  for(i=0;i<TREE_MAX-3;i++)
    if(map[i]>"")
      n = i;

// Display up to max

  cout << std::left;
  for(i=0;i<=n;i+=4)
    { cout << setw(4) << i+0 << setw(16) << map[i+0];
      cout << setw(4) << i+1 << setw(16) << map[i+1];
      cout << setw(4) << i+2 << setw(16) << map[i+2];
      cout << setw(4) << i+3 << setw(16) << map[i+3];
      cout << endl;
    };
  cout << endl;
}

/****************************
 * lmr()
 ****************************/
void tree::lmr(int pos)
{ if(pos>=TREE_MAX || map[pos]=="") return;
  lmr(left(pos));
  cout << map[pos] << endl;
  lmr(right(pos));
}

/****************************
 * mlr()
 ****************************/
void tree::mlr(int pos)
{ if(pos>=TREE_MAX || map[pos]=="") return;
  cout << map[pos] << endl;
  mlr(left(pos));
  mlr(right(pos));
}

/****************************
 * lmr()
 ****************************/
void tree::rml(int pos)
{ if(pos>=TREE_MAX || map[pos]=="") return;
  rml(right(pos));
  cout << map[pos] << endl;
  rml(left(pos));
}

/****************************
 * depth()
 ****************************/
int tree::depth(int pos)
{ int l,r;

// Return if bottom or empty node

  if(pos>=TREE_MAX) return 0;
  if(map[pos]=="") return 0;

// Left,Right

  l = depth(left(pos));
  r = depth(right(pos));  

// Max of both sides + middle

  return max(l,r)+1;
}