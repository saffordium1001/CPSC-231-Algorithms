/**********************************************
 * Lab 06
 * Written by Mark M Bowman
 **********************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define ARRAY_MAX  10000
#define NOT_FOUND  -1

int file_search(string map[],int n);
int linear(string map[],string item,int n);
int binary(string map[],string item,int n);
void sort(string map[],int n);

long counter;

int (*search)(string *,string,int);

/**********************************************
 * main()
 **********************************************/
void main()
{ int pos,data_n,search_n,sum;
  string fname,map[ARRAY_MAX],item;
  fstream infile;

// Initialize

  counter = 0;
  data_n = 0;
  search_n = 0;
  search = &binary;

// Open data file

  cout << "Enter data file name: ";
  cin >> fname;
  infile.open(fname.data(),ios::in);

// Loop through data file

  while(data_n<ARRAY_MAX && !infile.eof())
    { infile >> map[data_n];
      if(infile.good()) data_n++;
    };

// Close data file

  infile.close();
  cout << "Data entries: " << data_n << endl;
  cout << endl;

/*
// Sort

  sort(map,data_n);
*/

// Test single search 

  /*
  cout << "Enter a search string: ";
  cin >> item;

  pos = search(map,item,data_n);

  cout << "Position = " << pos << endl;
  cout << "Count = " << counter << endl << endl;
  */

// Search files

  do { sum = file_search(map,data_n);
       search_n += sum;
     } while(sum>0);
  cout << endl;

// Statistics

  cout << "Total search comparisons: " << counter << endl;
  cout << "Total search entries: " << search_n << endl;
  cout << "Total Comparisons/Entries: " << counter/search_n << endl;

}

/**********************************************
 * file_search()
 **********************************************/
int file_search(string map[],int n)
{ int pos,item_n,old_counter;
  string fname,item;
  fstream infile;

// Initialize

  item_n = 0;
  old_counter = counter;

// Open search file

  cout << "Enter search file name: ";
  cin >> fname;
  infile.open(fname.data(),ios::in);
  if(!infile.is_open()) return 0;

// Loop through search file

  infile.clear();
  while(!infile.eof())
    { infile >> item;
      if(infile.good())
        { pos = search(map,item,n);
          item_n++;
        };
    };

// Close data file

  infile.close();

// Stats for this file

  cout << "  Search comparisons: " << counter-old_counter << endl;
  cout << "  Search entries: " << item_n << endl;
  cout << "  Comparisons/Entries: " << (counter-old_counter)/item_n << endl;
  cout << endl;

// Return number of items

  return item_n;
}
