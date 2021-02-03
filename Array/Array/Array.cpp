#include<iostream>
#include"Array.h"
using namespace std;
Array::Array()
{
	data = nullptr;
	capacity = 0;
}
Array::Array(int cap)
{
	capacity = cap;
	if (capacity > 0)
	{
		data = new int[capacity];
	}

}
int Array::isValidIndex(int index) const
{
	if (index >= 0 && index < capacity)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int & Array::getSet(int index)
{
	if (isValidIndex(index) == 1)
	{
		return data[index];
	}
	else
	{
		exit(0);
	}
}
Array::~Array()
{
	if (data)
	{
		delete[] data;
	}
	data = 0;
	capacity = 0;
}
int Array::getCapacity() const
{
	return capacity;
}
void Array::reize(int newCapacity)
{
	if (newCapacity <= 0)
	{
		this->~Array();
	}
	int *temp = new int[newCapacity];
	int i = 0;
	while (i < capacity && i < newCapacity)
	{
		temp[i] = data[i];
		i = i + 1;
	}
	this->~Array();
	data = temp;
	capacity = newCapacity;
}
const int & Array::getSet(int index) const
{
	if (isValidIndex(index) == 1)
	{
		return data[index];
	}
	else
	{
		exit(0);
	}
}
Array::Array(const Array & ref)
{
	int i = 0;
	if (ref.data == 0)
	{
		data = 0;
		capacity = 0;
		return;
	}
	capacity=ref.capacity; 
	data = new int [capacity];
	while (i < capacity && i < ref.capacity)
	{
		data[i] = ref.data[i];
		i = i + 1;
	}
}
void Array::display(const Array & ref)
{
	for (int i = 0; i < ref.getCapacity(); i++)
	{
		cout << ref.getSet(i) << " ";
		cout << endl;
	}
}