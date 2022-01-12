/**********************************************
 * Node.h
 * Written by Mark M Bowman
 **********************************************/

class list;

class node
{ friend class list;
  public:
    node(string arg="");              // Constructor
    void put(ostream& out);           // Output node
    void forward(ostream &,node *);   // Recursive forwards output
    void backward(ostream &,node *);  // Recursive backwards output
  private:
    string name;                      // Data
    node* next;                       // Link to the next node
};
