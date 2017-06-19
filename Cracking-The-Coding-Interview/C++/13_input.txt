#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define NAME_SIZE 50

class Person {
private:
	int id;
	char name[NAME_SIZE];

public:
	Person() {}

	Person(int d) : id(d) {}

	virtual ~Person() {
		cout << "del person" << endl;
	}

	void aboutMe() {
		cout << "I am a person" << endl;
	}

	virtual bool addCourse(string s) = 0;
};

class Student : public Person {
public:
	void aboutMe() {
		cout << "I am a student" << endl;
	}

	~Student() {
		cout << "del student" << endl;
	}

	bool addCourse(string s) {
		cout << "add class " << s << endl;
		return true;
	}
};

int main()
{
	Person *p = new Student();
	p->aboutMe();
	p->addCourse("Math");

	delete p;

	return 0;
}
