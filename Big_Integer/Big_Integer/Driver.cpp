// C++ program to find sum of two large numbers. 
#include <string>
#include <iostream>
#include <vector>
#include "BigInteger.h"
using namespace std;


// Driver code 
int main()
{
	BigInteger * i = new BigInteger();
	BigInteger * j = new BigInteger();
	cin >> *i;
	cin >> *j;
	cout << *i + *j<< endl;
	cout << *i - *j << endl;
	cout << *i * *j << endl;
	cout << *i / *j << endl;
	delete i;
	delete j;
	return 0;
}
