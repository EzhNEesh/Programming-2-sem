#pragma once
#include<iterator>

template <typename T>
class CircIter :public std::iterator<std::random_access_iterator_tag, T>
{
public:
	CircIter() : _data(nullptr), _cap(0), _start(0), _end(0), _pos(0) {};
	CircIter(T* data, size_t cap, int& start, int& end, int& pos) : _data(data), _cap(cap), _start(start), _end(end), _pos(pos) {};
	
	bool operator != (CircIter const& comp) const
	{
		return this->_pos % _cap != comp._pos % _cap;
	}

	bool operator == (CircIter const& comp) const 
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

	CircIter operator + (const int& pos) const
	{
		CircIter it = *this;
		it._pos = (_pos + pos) % _cap;
		return it;
	}

	CircIter operator - (const int& pos) const
	{
		CircIter it = *this;
		it._pos = (_pos + _cap - pos) % _cap;
		return it;
	}

	CircIter operator + (const CircIter& iter) const
	{
		CircIter iterator = *this;
		iterator._pos += iter._pos;
		return *iterator;
	}

	CircIter operator - (const CircIter& iter) const
	{
		CircIter iterator = *this;
		iterator._pos -= iter._pos;
		return *iterator;
	}

	CircIter operator ++ ()
	{
		this->_pos++;
		return *this;
	}

	CircIter operator ++ (int)
	{
		CircIter it(*this);
		operator++();
		return it;
	}

	CircIter operator -- ()
	{
		this->_pos--;
		return *this;
	}

	CircIter operator -- (int)
	{
		CircIter it(*this);
		operator--();
		return it;
	}

	typename CircIter::reference operator*() const 
	{
		return _data[_pos];
	}

private:
	T* _data;
	int _pos;
	int _start;
	int _end;
	size_t _cap;
};
