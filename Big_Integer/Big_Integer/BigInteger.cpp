#include "BigInteger.h"





BigInteger::BigInteger()
{
	this->num = "0";
}

BigInteger::BigInteger(const string num)
{
	if (num != "") {
		this->num = num;
	}
	else {
		this->num = "0";
	}
}

BigInteger::BigInteger(const int num)
{
	this->num = to_string(num);
}

BigInteger::BigInteger(const BigInteger& bigInt)
{
	this->num = bigInt.num;
}

BigInteger& BigInteger::operator=(const BigInteger& bigInt)
{
	if (this != &bigInt) {
		this->num = bigInt.num;
	}
	return *this;
}

BigInteger BigInteger::operator+(const BigInteger& bigInt) const
{
	return BigInteger(add(this->num, bigInt.num));
}

BigInteger BigInteger::operator-(const BigInteger& bigInt) const
{
	return BigInteger(sub(this->num, bigInt.num));
}

BigInteger BigInteger::operator*(const BigInteger& bigInt) const
{
	return BigInteger(mul(this->num, bigInt.num));

}

BigInteger BigInteger::operator/(const BigInteger& bigInt) const
{
	return BigInteger(div(this->num, bigInt.num));
}

void* BigInteger::operator new(size_t size)
{
	void* p = ::new BigInteger();
	return p;
}

void BigInteger::operator delete(void* p)
{
	free(p);
}

string BigInteger::add(string str1, string str2) const
{
	string sign = "";
	if (str1.at(0) == '-' && str2.at(0) != '-')
	{
		str1 = str1.substr(1);
		return sub(str2, str1);
	}
	else if (str1.at(0) != '-' && str2.at(0) == '-')
	{
		str2 = str2.substr(1);
		return sub(str1, str2);
	}
	else if (str1.at(0) == '-' && str2.at(0) == '-')
	{
		sign = "-";
		str1 = str1.substr(1);
		str2 = str2.substr(1);
	}

	while (str1.length() > 1 && str1[0] == '0') {
		str1 = str1.substr(1);
	}

	while (str2.length() > 1 && str1[0] == '0') {
		str1 = str1.substr(1);
	}
	// Before proceeding further, make sure length 
	// of str2 is larger. 
	if (str1.length() > str2.length())
		swap(str1, str2);

	// Take an empty string for storing result 
	string str = "";

	// Calculate length of both string 
	int n1 = str1.length(), n2 = str2.length();

	// Reverse both of strings 
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;
	for (int i = 0; i < n1; i++)
	{
		// Do school mathematics, compute sum of 
		// current digits and carry 
		int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');

		// Calculate carry for next step 
		carry = sum / 10;
	}

	// Add remaining digits of larger number 
	for (int i = n1; i < n2; i++)
	{
		int sum = ((str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	// Add remaining carry 
	if (carry)
		str.push_back(carry + '0');

	// reverse resultant string 
	reverse(str.begin(), str.end());

	return sign + str;
}

bool isSmaller(string str1, string str2)
{
	// Calculate lengths of both string
	int n1 = str1.length(), n2 = str2.length();

	if (n1 < n2)
		return true;
	if (n2 < n1)
		return false;

	for (int i = 0; i < n1; i++)
		if (str1[i] < str2[i])
			return true;
		else if (str1[i] > str2[i])
			return false;

	return false;
}

// Function for find difference of larger numbers
string BigInteger::sub(string str1, string str2) const
{
	string sign = "";
	if (str1.at(0) == '-' && str2.at(0) != '-')
	{
		sign = "-";
		str1 = str1.substr(1);
		return sign + add(str1, str2);
	}
	else if (str1.at(0) != '-' && str2.at(0) == '-')
	{
		str2 = str2.substr(1);
		return add(str1, str2);
	}
	else if (str1.at(0) == '-' && str2.at(0) == '-')
	{
		str1 = str1.substr(1);
		str2 = str2.substr(1);
		return sub(str2, str1);
	}

	while (str1.length() > 1 && str1[0] == '0') {
		str1 = str1.substr(1);
	}

	while (str2.length() > 1 && str1[0] == '0') {
		str1 = str1.substr(1);
	}

	// Before proceeding further, make sure str1
	// is not smaller
	if (isSmaller(str1, str2)) {
		swap(str1, str2);
		sign = "-";
	}

	// Take an empty string for storing result
	string str = "";

	// Calculate length of both string
	int n1 = str1.length(), n2 = str2.length();

	// Reverse both of strings
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;

	// Run loop till small string length
	// and subtract digit of str1 to str2
	for (int i = 0; i < n2; i++) {
		// Do school mathematics, compute difference of
		// current digits

		int sub
			= ((str1[i] - '0') - (str2[i] - '0') - carry);

		// If subtraction is less then zero
		// we add then we add 10 into sub and
		// take carry as 1 for calculating next step
		if (sub < 0) {
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

	// subtract remaining digits of larger number
	for (int i = n2; i < n1; i++) {
		int sub = ((str1[i] - '0') - carry);

		// if the sub value is -ve, then make it positive
		if (sub < 0) {
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

	// reverse resultant string
	reverse(str.begin(), str.end());

	return sign + str;
}

string BigInteger::mul(string str1, string str2) const
{
	string sign = "";
	if ((str1.at(0) == '-' || str2.at(0) == '-') && (str1.at(0) != '-' || str2.at(0) != '-')) {
		sign = "-";
	}

	if (str1.at(0) == '-' && str2.at(0) != '-')
	{
		str1 = str1.substr(1);
	}
	else if (str1.at(0) != '-' && str2.at(0) == '-')
	{
		str2 = str2.substr(1);
	}
	else if (str1.at(0) == '-' && str2.at(0) == '-')
	{
		str1 = str1.substr(1);
		str2 = str2.substr(1);
	}

	int len1 = str1.size();
	int len2 = str2.size();
	if (len1 == 0 || len2 == 0)
		return "0";

	// will keep the result number in vector 
	// in reverse order 
	vector<int> result(len1 + len2, 0);

	// Below two indexes are used to find positions 
	// in result.  
	int intA = 0;
	int intB = 0;

	// Go from right to left in num1 
	for (int i = len1 - 1; i >= 0; i--)
	{
		int carry = 0;
		int n1 = str1[i] - '0';

		// To shift position to left after every 
		// multiplication of a digit in num2 
		intB = 0;

		// Go from right to left in num2              
		for (int j = len2 - 1; j >= 0; j--)
		{
			// Take current digit of second number 
			int n2 = str2[j] - '0';

			// Multiply with current digit of first number 
			// and add result to previously stored result 
			// at current position.  
			int sum = n1 * n2 + result[intA + intB] + carry;

			// Carry for next iteration 
			carry = sum / 10;

			// Store result 
			result[intA + intB] = sum % 10;

			intB++;
		}

		// store carry in next cell 
		if (carry > 0)
			result[intA + intB] += carry;

		// To shift position to left after every 
		// multiplication of a digit in num1. 
		intA++;
	}

	// ignore '0's from the right 
	int i = result.size() - 1;
	while (i >= 0 && result[i] == 0)
		i--;

	// If all were '0's - means either both or 
	// one of num1 or num2 were '0' 
	if (i == -1)
		return "0";

	// generate the result string 
	string s = "";

	while (i >= 0)
		s += std::to_string(result[i--]);

	return sign + s;
}

string BigInteger::div(string str1, string str2) const
{
	string sign = "";
	if ((str1.at(0) == '-' || str2.at(0) == '-') && (str1.at(0) != '-' || str2.at(0) != '-')) {
		sign = "-";
	}

	if (str1.at(0) == '-' && str2.at(0) != '-')
	{
		str1 = str1.substr(1);
	}
	else if (str1.at(0) != '-' && str2.at(0) == '-')
	{
		str2 = str2.substr(1);
	}
	else if (str1.at(0) == '-' && str2.at(0) == '-')
	{
		str1 = str1.substr(1);
		str2 = str2.substr(1);
	}

	while (str1.length() > 1 && str1[0] == '0') {
		str1 = str1.substr(1);
	}

	while (str2.length() > 1 && str1[0] == '0') {
		str1 = str1.substr(1);
	}

	string quotient = "0";
	while (true) {
		str1 = sub(str1, str2);
		if (str1[0] == '-') {
			break;
		}
		else {
			quotient = add(quotient, "1");
		}
	}
	return sign + quotient;
}

BigInteger::~BigInteger()
{
	num = "0";
}

ostream& operator<<(ostream& os, const BigInteger& bigInt)
{
	os << bigInt.num;
	return os;
}

istream& operator >> (istream& in, BigInteger& bigInt)
{
	cout << "Enter Big Integer: ";
	in >> bigInt.num;
	return in;
}

