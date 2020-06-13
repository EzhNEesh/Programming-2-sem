#pragma once
#include "CircBuffIter.h"

template<typename T>
class CircularBuffer
{
public:
	
	CircularBuffer() :
		quantity(0), start(0), finish(0), arr(nullptr), capacity(0) {};

	CircularBuffer(const int& size)
	{
		arr = new T[size];
		capacity = size;
		start = 0;
		finish = 0;
		quantity = 0;
	}

	T& operator[](const int& i) const
	{
		return arr[(start + i) % capacity];
	}

	CircIter<T> begin()
	{
		CircIter<T> iter(arr, capacity, start, finish, start);
		return iter;
	}

	CircIter<T> end()
	{
		CircIter<T> iter(arr, capacity, start, finish, finish);
		return iter;
	}

	void push_back(const T value)
	{
		if (start % capacity - finish % capacity == 1)
			start = (start + 1) % capacity;
		else
			quantity++;
		arr[finish % capacity] = value;
		finish = (finish + 1) % capacity;
	}

	void pop_back()
	{
		if (quantity > 0)
		{
			finish = (finish + capacity - 1) % capacity;
			quantity--;
		}
		else
		{
			std::cout << "Buffer is empty";
		}
	}

	void push_begin(const T value)
	{
		if (finish % capacity - start % capacity == 1 || (finish == capacity - 1 && start == 0))
		{
			finish = (finish + capacity - 1) % capacity;
		}
		else
			quantity++;
		start = (start + capacity - 1) % capacity;
		arr[start % capacity] = value;
	}

	void pop_begin()
	{
		if (quantity > 0)
		{
			start = (start + 1) % capacity;
			quantity--;
		}
		else
		{
			std::cout << "Buffer is empty";
		}
	}

	size_t size()
	{
		return quantity;
	}

	void resize(const int& new_cap)
	{
		T* buffer = new T[new_cap];
		int max_size = 0;
		for (int i = 0; i < new_cap; i++)
		{
			if (i == quantity)
				break;
			buffer[i] = operator[](i);
			max_size++;
		}
		delete[] arr;
		arr = new T[new_cap + 1];
		for (int i = 0; i < max_size; i++)
			arr[i] = buffer[i];
		quantity = max_size;
		capacity = new_cap + 1;
		start = 0;
		finish = quantity;
		delete[] buffer;
	}

	CircIter<T> erase(const CircIter<T>& iterator)
	{
		if (iterator == begin())
		{
			pop_begin();
			return begin();
		}
		else if (iterator == end())
		{
			pop_back();
			return end() - 1;
		}
		else
		{
			T* buffer = new T[capacity];
			int max_size = 0;
			int pos_now = -1;
			auto iter = begin();
			for (int i = 0; i < quantity; i++)
			{
				if (iter == iterator)
				{
					pos_now = i;
					i++;
				}
				buffer[i % capacity] = operator[](i% capacity);
				iter++;
				max_size++;
			}
			delete[] arr;
			arr = new T[capacity];
			int j = 0;
			for (int i = 0; i < max_size; i++)
			{
				if (j == pos_now)
					j++;
				arr[i] = buffer[j];
				j++;
			}
			start = 0;
			finish = max_size % capacity;
			quantity = max_size;
			if (quantity > capacity)
				quantity = capacity;
			delete[] buffer;
			return begin() + pos_now;
		}
	}

	CircIter<T> insert(const CircIter<T>& iterator, const T& value)
	{
		if (iterator == begin())
		{
			push_begin(value);
			return begin();
		}
		else if (iterator == end())
		{
			push_back(value);
			return end() - 1;
		}
		else
		{
			T* buffer = new T[capacity];
			int max_size = 0;
			int pos_now = -1;
			auto iter = begin();
			for (int i = 0; i < quantity; i++)
			{
				if (iter == iterator)
				{
					pos_now = i;
					buffer[i % capacity] = value;
					max_size++;
					i++;
				}
				buffer[i % capacity] = operator[](i% capacity);
				iter++;
				max_size++;
			}
			delete[] arr;
			arr = new T[capacity];
			for (int i = 0; i < max_size; i++)
				arr[i] = buffer[i];
			start = 0;
			finish = max_size % capacity;
			quantity = max_size;
			if (quantity > capacity)
				quantity = capacity;
			delete[] buffer;
			return begin() + pos_now;
		}
	}

	~CircularBuffer()
	{
		delete[] arr;
	}

private:
	int start;
	int finish;
	int capacity;
	int quantity;
	T* arr;
};
