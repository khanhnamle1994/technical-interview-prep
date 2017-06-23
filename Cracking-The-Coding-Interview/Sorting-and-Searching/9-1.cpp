// You are given 2 sorted arrays, A and B, and A has a large enough buffer at the end to hold B. Write a method to merge B into A in
// sorted order.

#include <iostream>
using namespace std;

void merge(int a[], int lastA, int b[], int lastB) {
	int index = lastB + lastA + 1;
	while(index >= 0) {
		if (a[lastA] > b[lastB]) {
			a[index] = a[lastA];
			lastA--;
		}
		else {
			a[index] = b[lastB];
			lastB--;
		}
		index--;
	}
}

int main(){

	int a[6] = {2, 5, 7, 12};
	int b[] = {3, 6};
	merge(a, 3, b, 1);
	for (int i = 0; i < 6; ++i) {
		cout<< a[i] << " ";
	}
	return 0;
}
