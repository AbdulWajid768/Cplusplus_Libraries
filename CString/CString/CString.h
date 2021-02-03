#ifndef  CSTRING_H
#define CSTRING_H
#include <iostream>
using namespace std;
class CString;
ostream & operator<<(ostream & x, const CString & s);
istream & operator >> (istream & x, CString & s);
class CString
{
	char * data;
	int size;
	bool isValidIndex(int index);
	void CString::strCopy(char * dest, const char * src) const;
	int CString::calLength(const char *p) const;
public:
	CString();
	CString(char c);
	CString(const char *);
	CString(const CString &);
	~CString();
	void shrink();
	void input();
	char & at(int index);
	bool isEmpty() const;
	int getLength() const;
	void display() const;
	int find(CString * subStr, int start = 0) const;
	void insert(int index, CString * subStr);
	void remove(int index, int count = 1);
	int replace(CString * old, CString * newSubStr);
	void trimLeft();
	void trimRight();
	void trim();
	void makeUpper();
	void makeLower();
	void reverse();
	void resize(int newcap);
	int compare(CString & s2) const;
	CString left(int count);
	CString rigth(int count);
	int tolnteger() const;
	float toFloat() const;
	CString concat(CString s2) const;
	void concatEqual(CString s2);
	CString tokenize(CString delim);
	CString & operator=(CString & ref);
	CString inToCString(int num);
	char & operator[](int index);
	int operator++();
	int operator++(int);

};
#endif // ! CSTRING_H
