// Bin class definition

class bin
{
public:
	bin(); // Constructor
	bool get(istream& in); // Input
	void put(ostream& out); // Output
	bool operator == (const bin& b); // Equal
	bool operator > (const bin& b); // greater
	bool operator < (const bin& b); // lesses
private:
	string name; // Name
	int count; // Count
};