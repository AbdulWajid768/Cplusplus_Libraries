#include<iostream>
#include"CString.h"
using namespace std;
int CString::calLength(const char *p) const
{
	int i = 0;
	while (p[i] != '\0')
	{
		i = i + 1;
	}
	return i;
}
void CString::strCopy(char * dest, const char * src) const
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
}
CString::CString()
{
	data = nullptr;
	size = 0;
}
CString::CString(const char c)
{
	data = new char[2]{ c,'\0' };
	size = 2;
}
CString::CString(const char * src)
{
	cout << "CString::CString(const char * src)" << endl;
	/*int i = 0;
	while (c[i] != '\0')
	{
	i = i + 1;
	}
	size = i + 1;
	data = new char[size];
	for (int j = 0; j < i; j = j + 1)
	{
	data[i] = c[i];
	}
	data[i] = '\0';*/
	int len = calLength(src);
	size = len + 1;
	data = new char[size];
	strCopy(data, src);
}
CString::~CString()
{
	if (data)
	{
		delete[] data;
	}
	data = nullptr;
	size = 0;
}
bool CString::isValidIndex(int index)
{
	if (index >= 0 && index < size)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void CString::input()
{
	int i = 0;
	char ch;
	do
	{
		cin.get(ch);
		resize(i + 1);
		data[i] = ch;
		i = i + 1;
	} while (ch != '\n');
	data[i - 1] = '\0';
}
char & CString::CString::at(int index)
{
	if (isValidIndex(index) == true)
	{
		return data[index];
	}
	else
	{
		exit(0);
	}

}
bool CString::isEmpty() const
{
	if (data)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int CString::getLength() const
{
	return calLength(data);
}
void CString::display() const
{
	cout << data << endl;
}
int CString::find(CString * subStr, int start) const
{
	int ld = calLength(data), lsd = calLength(subStr->data), match = 0, count = 0;
	if (lsd > ld)
	{
		return 0;
	}
	for (int i = start; i <= ld - lsd; i = i + 1)
	{
		match = 0;
		for (int j = 0; j < lsd; j = j + 1)
		{
			if (data[i + j] == subStr->data[j])
			{
				match = match + 1;
			}
		}
		if (match == lsd)
		{
			count = count + 1;
			start = i + lsd;
		}
	}
	return count;
}
void CString::insert(int index, CString * subStr)
{

	int lsd = calLength(subStr->data), ld = calLength(data), j = 0;
	if (index < 0 || index > ld - 1)
	{
		exit(0);
	}
	if (size < ld + lsd + 1)
	{
		resize(ld + lsd + 1);
	}
	for (int i = ld; i >= index; i--)
	{
		data[i + lsd] = data[i];
	}
	for (int i = index; i < lsd + index; i++)
	{
		data[i] = subStr->data[j];
		j = j + 1;
	}
	//OLD
	//int ld = calLength(data), lsd = calLength(subStr->data), j = 0;
	//if (index > ld - 1)
	//{
	//	exit(0);
	//}
	//if (size < ld + lsd + 1)
	//{
	//	resize(ld + lsd + 1);
	//}
	//for (int i = ld; i >= index; i--)
	//{
	//	data[i + lsd] = data[i];
	//}
	//for (int i = index; i < lsd + index; i++)
	//{
	//	data[i] = subStr->data[j];
	//	j = j + 1;
	//}
}
void CString::remove(int index, int count)
{
	int ld = calLength(data);
	if (count >= 0 && count < ld && ((index + count) <= ld))
	{
		char * temp = new char[ld - count + 1];
		int j = 0;
		for (int i = 0; i < index; i = i + 1)
		{
			temp[i] = data[i];
		}
		j = index;
		for (int i = index + count; i < ld; i = i + 1)
		{
			temp[j] = data[i];
			j = j + 1;
		}
		temp[j] = '\0';
		delete[] data;
		data = temp;
	}
	else
	{
		exit(0);
	}
}
int CString::replace(CString * old, CString * newSubStr)
{
	int lod = calLength(old->data), lnd = calLength(newSubStr->data), match = 0, count = 0, start = 0;
	for (int i = start; i <= calLength(data) - lod; i = i + 1)
	{
		match = 0;
		for (int j = 0; j < lod; j = j + 1)
		{
			if (data[i + j] == old->data[j])
			{
				match = match + 1;
			}
		}
		if (match == lod)
		{
			count = count + 1;
			start = i + lnd;
			remove(i, lod);
			insert(i, newSubStr);
		}
	}
	return count;
}
void CString::trimLeft()
{
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			break;
		}
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			break;
		}
		i = i + 1;
	}
	remove(0, i);
}
void CString::trimRight()
{
	int i = calLength(data) - 1, count = 0;
	while (i > 0)
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			break;
		}
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			break;
		}
		count = count + 1;
		i = i - 1;
	}
	remove(i + 1, count);
}
void CString::trim()
{
	trimLeft();
	trimRight();
}
void CString::makeUpper()
{
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			data[i] = data[i] - 32;
		}
		i = i + 1;
	}
}
void CString::makeLower()
{
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			data[i] = data[i] + 32;
		}
		i = i + 1;
	}
}
void CString::reverse()
{
	int ld = calLength(data), j = ld - 1;
	char temp;
	for (int i = 0; i < ld / 2; i = i + 1)
	{
		temp = data[i];
		data[i] = data[j];
		data[j] = temp;
		j = j - 1;
	}
}
void CString::resize(int newCap)
{
	if (newCap <= 0)
	{
		delete[] data;
		data = nullptr;
		size = 0;
		return;
	}
	char *temp = new char[newCap];
	int i = 0;
	if (data != nullptr)
	{
		while (i < calLength(data) && i < newCap - 1)
		{
			temp[i] = data[i];
			i = i + 1;
		}
	}
	temp[i] = '\0';
	delete[] data;
	data = temp;
	size = newCap;
	//if (newCap <= 0)
	//{
	//	delete[] data;
	//	data = nullptr;
	//	size = 0;
	//	return;
	//}
	//char *temp = new char[newCap];
	//int i = 0;
	//while (i < calLength(data) && i < newCap - 1)
	//{
	//	temp[i] = data[i];
	//	i = i + 1;
	//}
	//temp[i] = '\0';
	//delete[] data;
	//data = temp;
	//size = newCap;
}
int CString::compare(CString & s2) const
{
	int ld = calLength(data), ls2 = calLength(s2.data), i = 0, count = 0, end;
	if (ld < ls2)
	{
		end = ld;
	}
	else//-1a>b      1a<b
	{
		end = ls2;
	}
	for (i = 0; i < end; i = i + 1)
	{
		if (data[i] == s2.data[i])
		{
			count = count + 1;
		}
		else
		{
			break;
		}
	}
	if (count == end && ld == ls2)
	{
		return 0;
	}
	if (count == end && ld < ls2 || count < end && data[count] < s2.data[count] /*|| count < end && a[count] >= 'A' &&  a[count] <= 'Z' && b[count] >= 'a' && b[count] >= 'z' )*/)
	{
		return -1;
	}
	if (count == end && ld > ls2 || count < end && data[count] > s2.data[count] /*|| count < end && b[count] >= 'A' &&  b[count] <= 'Z' && a[count] >= 'a' && a[count] >= 'z' )*/)
	{
		return 1;
	}
}
void CString::shrink()
{
	resize(calLength(data) + 1);
}
CString CString::left(int count)
{
	CString temp;
	char*a = new char[count + 1];
	int i;
	for (i = 0; i < count; i = i + 1)
	{
		a[i] = data[i];
	}
	a[i] = '\0';
	temp.data = a;
	temp.size = count + 1;
	a = nullptr;
	return temp;
}
CString CString::rigth(int count)
{
	CString temp;
	char*a = new char[count + 1];
	int i, ld = calLength(data), j = 0;
	for (i = ld - count; i < ld; i = i + 1)
	{
		a[j] = data[i];
		j = j + 1;
	}
	a[j] = '\0';
	temp.data = a;
	temp.size = count + 1;
	a = nullptr;
	return temp;
}
int CString::tolnteger() const
{
	int num = 0, i = 0;
	if (data[0] == '+' || data[0] == '-')
	{
		i = i + 1;
	}
	while (data[i] != '\0')
	{
		if (data[i] < '0' || data[i] > '9')
		{
			exit(0);
		}
		num = num * 10 + ((int)data[i] - 48);
		i = i + 1;
	}
	if (data[0] == '-')
	{
		num = num - (num * 2);
	}
	return num;
}
float CString::toFloat() const
{
	int i = 0, j = 1;
	float num = 0;
	if (data[0] == '+' || data[0] == '-')
	{
		i = i + 1;
	}
	while (data[i] != '.')
	{
		if (data[i] < '0' || data[i] > '9')
		{
			exit(0);
		}
		num = num * 10 + ((float)data[i] - 48);
		i = i + 1;
	}
	i = i + 1;
	while (data[i] != '\0')
	{
		if (data[i] < '0' || data[i] > '9')
		{
			exit(0);
		}
		num = num + ((float)data[i] - 48) / pow(10, j);
		i = i + 1;
		j = j + 1;
	}
	if (data[0] == '-')
	{
		num = num - (num * 2);
	}
	return num;
}CString CString::concat(CString s2) const
{
	char * a;
	CString b;
	int ld = calLength(data), ls2 = calLength(s2.data), i = 0;
	a = new char[ld + ls2 + 1];
	for (int j = 0; j < ld; j = j + 1)
	{
		a[i] = data[j];
		i = i + 1;
	}
	for (int j = 0; j < ls2; j = j + 1)
	{
		a[i] = s2.data[j];
		i = i + 1;
	}
	a[i] = '\0';
	b.data = a;
	b.size = ld + ls2 + 1;
	a = nullptr;
	return b;
}
void CString::concatEqual(CString s2)
{
	int ld = calLength(data), ls2 = s2.calLength(s2.data), i = 0, j = ld;
	resize(ld + ls2 + 1);
	while (s2.data[i] != '\0')
	{
		data[j] = s2.data[i];
		j = j + 1;
		i = i + 1;
	}
	data[j] = '\0';
}
CString::CString(const CString & ref)
{
	cout << "CString::CString(const CString & ref)" << endl;
	if (ref.data == nullptr)
	{
		data = nullptr;
		size = 0;
		return;
	}
	size = ref.size;
	data = new char[size];
	strCopy(data, ref.data);
}
CString CString::tokenize(CString delim)
{
	int ld = calLength(data), ldel = calLength(delim.data), i, j, index = ld - 1;
	for (i = 0; i < ldel; i = i + 1)
	{
		for (j = 0; j < ld; j = j + 1)
		{
			if (delim.data[i] == data[j])
			{
				if (j <= index)
				{
					index = j;
				}
				break;
			}
		}
	}
	char * temp = new char[index + 1];
	i = 0;
	for (i = 0; i < index; i = i + 1)
	{
		temp[i] = data[i];
	}
	temp[i] = '\0';
	remove(0, index + 1);
	CString token(temp);
	temp = nullptr;
	return token;
}
CString & CString::operator=(CString & ref)
{
	cout << "CString & CString::operator=(CString & ref)" << endl;
	if (this == &ref)
	{
		return *this;
	}
	if (ref.data == nullptr)
	{
		data = nullptr;
		size = 0;
		return *this;
	}
	size = ref.size;
	data = new char[size];
	strCopy(data, ref.data);
	return *this;
}

CString CString::inToCString(int num)
{
	char r;
	int i = 0;
	while (num != 0)
	{
		resize(i + 1);
		data[i] = num % 10 + 48;
		num = num / 10;
		i = i + 1;
	}
	resize(i + 1);
	data[i] = '\0';
	reverse();
	return *this;
}

char & CString::operator[](int index)
{
	return at(index);
}

int CString::operator++()
{
	cout << "++S" << endl;
	return 0;
}

int CString::operator++(int)
{
	cout << "S++" << endl;
	return 0;
}

ostream & operator<<(ostream & x, const CString & s)
{
	s.display();
	return x;
}
istream & operator >> (istream & x, CString & s)
{
	s.input();
	return x;
}