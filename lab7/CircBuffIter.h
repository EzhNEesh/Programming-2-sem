#pragma once
#include<iterator>


template <typename T>
class CircIter :public std::iterator<std::random_access_iterator_tag, T>
{
public:
	CircIter() : _data(nullptr), _pos(nullptr), _start(nullptr), _end(nullptr), _cap(0) {};
	CircIter(T* data, T* pos, T* start, T* end, size_t cap) : _data(data), _pos(pos), _start(start), _end(end), _cap(cap) {};
	
	bool operator != (CircIter const& comp) const
	{
		return this->_pos != comp._pos;
	}

	bool operator == (CircIter const& comp) const //check
	{
		return this->_pos % _cap == comp._pos % _cap;
	}
	
	bool operator > (CircIter const& comp) const
	{
		if (_start > _end)
		{
			if (this->_pos < _cap && comp._pos < _cap)
				return this->_pos > comp._pos;
			else if (this->_pos < _cap)
				return false;
			else if (comp._pos < _cap)
				return true;
		}
		return this->_pos > comp._pos;
	}

	bool operator >= (CircIter const& comp) const
	{
		if (_start > _end)
		{
			if (this->_pos < _cap && comp._pos < _cap)
				return this->_pos >= comp._pos;
			else if (this->_pos < _cap)
				return false;
			else if (comp._pos < _cap)
				return true;
		}
		return this->_pos >= comp._pos;
	}

	bool operator < (CircIter const& comp) const
	{
		if (_start > _end)
		{
			if (this->_pos < _cap && comp._pos < _cap)
				return this->_pos < comp._pos;
			else if (this->_pos < _cap)
				return true;
			else if (comp._pos < _cap)
				return false;
		}
		return this->_pos < comp._pos;
	}

	bool operator <= (CircIter const& comp) const
	{
		if (_start > _end)
		{
			if (this->_pos < _cap && comp._pos < _cap)
				return this->_pos <= comp._pos;
			else if (this->_pos < _cap)
				return true;
			else if (comp._pos < _cap)
				return false;
		}
		return this->_pos <= comp._pos;
	}

private:
	T* _data;
	T* _pos;
	int _start;
	int _end;
	size_t _cap;
};