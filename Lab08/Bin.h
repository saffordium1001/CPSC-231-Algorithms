// Bin class definition

class bin
{ public:
    bin();                            // Constructor
    bool get(istream &in);            // Input
    void put(ostream &out);           // Output
    bool operator == (const bin &b);  // Equal
  private:
    string name;                      // Name
    int count;                        // Count
};
