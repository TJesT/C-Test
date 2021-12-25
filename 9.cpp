#include <iostream>
#include <string>

template<class T>
class DynamicArray
{
public:
	DynamicArray(){}
	explicit DynamicArray(const size_t amm, T elem) : _data(new T[amm]), _size(amm), _buf_size(amm) {
		for(int i = 0; i < _size; ++i) {
			_data[i] = elem;
		}
	}

	void PushBack(const T& new_elem)
	{
		if(_size == _buf_size) {
			if(_buf_size == 0) {
				_data = new T[1];
				_buf_size = 1;
			}
			else {
				T* old_data = _data;
				_data = new T[_buf_size * 2];
				for(int i = 0;i < _size; ++i) {
					_data[i] = old_data[i];
				}
				delete old_data;
				_buf_size *= 2;
			}
		}
		_data[_size] = new_elem;
		_size++;
	}

	T& operator[](const size_t index) {
		return _data[index];
	}

	const T& operator[](const size_t index) const {
		return _data[index];
	}

	~DynamicArray() {
		delete[] _data;
	}

	class ArrayIterator {
	public:
		typedef T value_type;
		typedef int difference_type;
		explicit ArrayIterator(const size_t index, T* storage) :
		_index(index),
		_data(storage)
		{}
		ArrayIterator& operator++()
		{
			_index++;
			return *this;
		}
		T& operator*()
		{
			return _data[_index];
		}
		T* operator->()
		{
			return &_data[_index];
		}
		int operator-(const ArrayIterator& other)
		{
			return _index - other._index;
		}

		bool operator==(const ArrayIterator& other)
		{
			return _data == other._data && _index == other._index;
		}

		bool operator!=(const ArrayIterator& other)
		{
			return !operator==(other);
		}
	private:
		size_t _index;
		T* _data;
	};

	ArrayIterator begin() {
		return ArrayIterator(0, _data);
	}

	ArrayIterator end() {
		return ArrayIterator(_size, _data);
	}
private:
	T* _data = nullptr;
	size_t _size = 0;
	size_t _buf_size = 0;
};
