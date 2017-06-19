// What is the difference between deep copy and shallow copy? Explain how you would use

#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct Test {
	char *ptr;
};

void shallow_copy(Test* src, Test* dst) {
	dst->ptr = src->ptr;
}

void deep_copy(Test* src, Test* dst) {
	dst->ptr = (char *) malloc(strlen(src->ptr) + 1);
	strcpy(dst->ptr, src->ptr);
}

int main() {
	Test *t1 = new Test();
	Test *t2 = new Test();
	Test *t3 = new Test();

	t1->ptr = (char *)malloc(sizeof(char) * 8);
	strcpy(t1->ptr, "ori");

	shallow_copy(t1, t2);
	deep_copy(t1, t3);

	cout << t1->ptr << " " << t2->ptr << " " << t3->ptr << endl;

	strcpy(t1->ptr, "mod");
	cout << t1->ptr << " " << t2->ptr << " " << t3->ptr << endl;

	return 0;
}
