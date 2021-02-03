#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BigInteger {
public:
	//Normal Constructor
	BigInteger();
	//Parameterized Constructor
	BigInteger(const string num);
	//Parameterized Constructor
	BigInteger(const int num);
	//Copy Constructor
	BigInteger(const BigInteger & bigInt);
	//Assignment Operator Overriding
	BigInteger& operator = (const BigInteger& bigInt);
	//Plus Operator Overriding
	BigInteger operator + (const BigInteger& bigInt) const;
	//Minus Operator Overriding
	BigInteger operator - (const BigInteger& bigInt) const;
	//Multiply Operator Overriding
	BigInteger operator * (const BigInteger& bigInt) const;
	//Division Operator Overriding
	BigInteger operator / (const BigInteger& bigInt) const;
	//Cout Operator Overriding
	friend ostream& operator<<(ostream& os, const BigInteger& bigInt);
	//Cin Operator Overriding
	friend istream& operator >> (istream& in, BigInteger& bigInt);
	//New Operator Overriding
	void* operator new(size_t size);
	//Delete Operator Overriding
	void operator delete(void* p);
	//Add Intergers In Two Strings
	string add(string str1, string str2) const;
	//Subtract Intergers In Two Strings
	string sub(string str1, string str2) const;
	//Multiply Intergers In Two Strings
	string mul(string str1, string str2) const;
	//Divide Intergers In Two Strings
	string div(string str1, string str2) const;
	//Destructor
	~BigInteger();
private:
	//String That Hold Integer
	string num;
};

#endif