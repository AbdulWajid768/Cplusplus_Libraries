#include<iostream>
#include"CString.h"
using namespace std;
class B
{
public:
	B()
	{
		cout << "B()" << endl;
	}
	B(B & ref)
	{
		cout << "B(B & ref)" << endl;
	}
	B & operator=(B & ref)
	{
		cout << "B & operator=(B & ref)" << endl;
	}
	operator B()
	{

	}
};
class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	A(A & ref)
	{
		cout << "A(A & ref)" << endl;
	}
	A & operator=(A & ref)
	{
		cout << "A & operator=(A & ref)" <<endl;
	}
	operator A()
	{

	}
};

void main()
{
	
	CString c = CString("hello");
	CString t = CString('0').concat(CString("jhdvbv dfg"));
	cout << t << endl;
	cout << t.getLength() << endl;
}