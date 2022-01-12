/**********************************************
 * Node.h
 * Written by Mark M Bowman
 **********************************************/

class node
{ friend void main();
  public:
    node(string args="");       // Constructor
    ~node();                    // Destructor 
    void add(node *argp);       // Add node link
    void put(ostream& out);     // Output node
  private:
    string name;                // Data
    node* next;                 // Link to the next node
};
