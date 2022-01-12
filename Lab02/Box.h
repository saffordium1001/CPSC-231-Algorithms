// Box class definition

class box
{ public:
    box();                      // Constructor - null
    box(int,int);               // Constructor - parameters
    ~box();                     // Destructor
    bool get(istream &in);      // Input dimensions
    void put(ostream &out);     // Output dimensions
    int  area();                // Calculate area
    int  perimeter();           // Calculate perimeter
  private:
    int height,width;           // Dimensions
};
