// Tree Declarations

#define TREE_MAX  1024
#define TREE_ERR  -1

inline int left(int pos) { return pos*2+1; }
inline int right(int pos) { return pos*2+2; }

class tree
{ public:
    tree();                         // Constructor
    tree(const tree& t);   // copy constructor
    bool insert(string);            // Insert string into tree
    void show(string);              // Display in order
    int  depth();                   // Total depth
    tree operator +(const tree &t);  // Combine trees
    void operator = (const tree &t);  // Comparison operator
  private:
    void dump();                    // Dump contents of array
    void lmr(int pos);              // Recursive LMR display
    void mlr(int pos);              // Recursive LMR display
    void rml(int pos);              // Recursive LMR display
    int  depth(int pos);            // Recursive depth function
    string map[TREE_MAX];           // Data array
};
