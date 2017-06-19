// Write a smart pointer class

#include <iostream>
#include <map>
#include <string>
using namespace std;

template <class T> class SmartPtr {
public:
	SmartPtr(T * ptr) {
		ref = ptr;
		ref_count = (unsigned *)malloc(sizeof(unsigned));
		*ref_count = 1;
	}

	SmartPtr(SmartPtr<T> & sptr) {
		ref = sptr.ref;
		ref_count = sptr.ref_count;
		++(*ref_count);
	}

	SmartPtr<T> & operator=(SmartPtr<T> & sptr) {
		if (this == &sptr)
			return *this;

		if (*ref_count > 0) {
			remove();
		}

		ref = sptr.ref;
		ref_count = sptr.ref_count;
		++(*ref_count);

		return *this;
	}

	~SmartPtr() {
		remove();
	}

	T getValue() {
		return *ref;
	}

protected:
	void remove() {
		--(*ref_count);

		if (*ref_count == 0) {
			delete ref;
			ref = NULL;
			free(ref_count);
			ref_count = NULL;
		}
	}

	T * ref;
	unsigned * ref_count;
};

int main() {
	char input[] = "haha";

	SmartPtr<char> a(input);

	cout << a.getValue() << endl;

	return 0;
}
