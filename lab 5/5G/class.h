#pragma once

using namespace std;

class qException
{
private:
	string m_error;
public:
	qException(string error)
	{
		m_error = error;
	}
	const char* getError() 
	{ 
		return m_error.c_str(); 
	}
};

template<int qLength, typename type>
class queue
{
private:
	struct list
	{
		type data;
		list* next;
	};
	list* first;
	list* last;
	int Cur;
public:
	queue()
	{
		first = NULL;
		last = NULL;
		Cur = 0;
	}

	void push(type D)
	{
		if (Cur >= qLength)
		{
			throw qException("Queue is overflow");
		}
		Cur++;
		list* newList = new list;
		if (last != NULL)
		{
			last->next = newList;
		}
		newList->data = D;
		newList->next = NULL;
		if (first == NULL)
		{
			first = newList;
		}
		last = newList;
	}

	type pop()
	{
		if (first == NULL)
		{
			throw qException("Queue is empty");
		}
		Cur--;
		type D = first->data;
		if (first == last)
		{
			delete first;
			first = NULL;
			last = NULL;
		}
		else
		{
			list* del = first;
			first = first->next;
			delete del;
		}
		return D;
	}
};