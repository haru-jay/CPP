#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib>
# include <stdexcept>

template<typename T>
class Array
{
public:
	Array():_arr(NULL), _size(0){}
	Array(unsigned int n)
	{
		_size = n;
		_arr = new T[n]();
	}
	~Array()
	{
		delete[] _arr;
	}

	Array(const Array &rhs):_arr(NULL), _size(0)
	{
		*this = rhs;
	}

	Array& operator=(const Array &rhs)
	{
		if(this != &rhs)
		{
			_size = rhs._size;
			delete[] _arr;
			_arr = new T[_size]();
			for (size_t i = 0; i < _size; i++)
			{
				_arr[i] = rhs._arr[i];
			}
		}
		return *this;
	}

	T& operator[](unsigned int i)
	{
		if(i >= _size)
			throw std::out_of_range("Out of range");
		return _arr[i];
	}

	size_t size() const
	{
		return _size;
	}

private:
	T *_arr;
	size_t _size;

};

#endif