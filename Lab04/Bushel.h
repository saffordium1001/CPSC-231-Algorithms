/*********************************
 * Bushel header
 * Created by Mark Bowman
 *********************************/

 /**************************************
  * Lab 04 - Extra Credit
  * Safford, Twymun - 01-Sep-2021
  *
  * Extra credit for lab 4 - add on
  * lemons and limes as fruits for code
 **************************************/
#define FRUIT_MAX  6
//update FRUIT_MAX to 6 for 6 different types of fruit and add to the array 
const string fruit_name[FRUIT_MAX] = { "Apples","Oranges","Peaches","Pears", "Lemons", "Limes"};

class bushel
{ public:
    bushel();                               // Constructor
    bool get(istream &);                    // Input
    void put(ostream &);                    // Output
 /**************************************
 * Operator + & - : Implementation/Solution
 * Safford, Twymun - 01-Sep-2021
**************************************/
    bushel operator + (const bushel &b);    // Addition
    bushel operator - (const bushel &b);    // Subtraction
  private:
    int map[FRUIT_MAX];                     // Fruit in basket
};
