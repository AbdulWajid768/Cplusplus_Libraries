class Array
{
private:
	int *data;
	int capacity;
	int isValidIndex(int index) const;
public:
	Array();
	Array(int cap = 0);
	~Array();
	int & getSet(int index);
	const int & getSet(int index) const;
	int getCapacity() const;
	void reize(int newCapacity);
	Array(const Array & ref);
	Array(int argCount, ...);
	void display(const Array & ref);
};
