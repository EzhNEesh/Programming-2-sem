#pragma once
#include "CircBuffIter.h"

template<typename T>
class CircularBuffer
{
public:
	
	CircularBuffer() :
		quantity(0), start(0), finish(0), arr(nullptr), capacity(0) {};

	CircularBuffer(const size_t& size)
	{
		arr = new T[size];
		std::fill(arr, arr + size, 0);
		capacity = size;
		start = 0;
		finish = 0;
		quantity = 0;
	}

	T& operator[](const size_t& i) const
	{
		return arr[(start + i) % capacity];
	}

	CircIter<T> begin()
	{
		CircIter<T> iter(arr, start, start, finish, capacity);
		return iter;
	}

	CircIter<T> end()
	{
		CircIter<T> iter(arr, finish, start, finish, capacity);
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

	T size()
	{
		return quantity;
	}

	void resize(const size_t& new_cap)
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

	void insert(const int& iterator, const T value)
	{
		arr[iterator] = value;
	}

	void erase(const int& iterator)
	{
		if (iterator == start)
		{
			pop_begin();
		}
		else if (iterator == finish - 1)
		{
			pop_back();
		}
		else
		{
			quantity--;
			T* buffer = new T[capacity];
			for (int i = 0; i < capacity; i++)
			{
				if (i == iterator)
					continue;
				buffer[i] = operator[](i);
			}
			delete[] arr;
			arr = new T[capacity + 1];
			for (int i = 0; i < capacity; i++)
				arr[i] = buffer[i];
			start = 0;
			finish = quantity;
			delete[] buffer;
		}
	}

	~CircularBuffer()
	{
		delete[] arr;
	}

private:
	int start;
	int finish;
	size_t capacity;
	size_t quantity;
	T* arr;
};