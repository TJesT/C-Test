template<class T>
class SharedPtr {
private:
	T* _ptr = nullptr;
	size_t* _ref_count = nullptr;

public:
	SharedPtr() : _ptr(nullptr), _ref_count(new size_t(0)){}

	SharedPtr(T* ptr) : _ptr(ptr), _ref_count(new size_t(1)){}

	SharedPtr(const SharedPtr& other) {
		this->_ptr = other._ptr;
		this->_ref_count = other._ref_count;
		
		if (other._ptr != nullptr)
		{
			(*_ref_count)++;
		}
	}

	SharedPtr& operator=(const SharedPtr& other) {
		clean();

		this->_ptr = other._ptr;
		this->_ref_count = other._ref_count;
		if (other._ptr != nullptr)
		{
			(*_ref_count)++;
		}

		return *this;
	}

	SharedPtr(SharedPtr&& other) {
		this->_ptr = other._ptr;
		this->_ref_count = other._ref_count;

		other._ptr = other._ref_count = nullptr;
	}

	SharedPtr& operator=(SharedPtr&& other) {
		clean();

		this->_ptr = other._ptr;
		this->_ref_count = other._ref_count;

		other._ptr = other._ref_count = nullptr;

		return *this;
	}

	size_t getCount() const {
		return *_ref_count;
	}

	T* get() const {
		return _ptr;
	}

	T* operator->() const {
		return _ptr;
	}

	T& operator*() const {
		return _ptr;
	}

	~SharedPtr() {
		clean();
	}
private:
	void clean() {
		(*_ref_count)--;
		if (*_ref_count == 0) {
			if (_ptr != nullptr)
				delete _ptr;
			delete _ref_count;
		}
	}
};