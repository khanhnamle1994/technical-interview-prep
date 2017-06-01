// Describe how you could use a single array to implement 3 stacks

// We can easily use an array to achieve a stack, push the stack into the array to insert the value, the top of the stack plus 1; stack
// directly on the top of the stack pointer by 1; take the top of the stack to the top of the stack pointer The value of the unit to
// return; to determine whether it is empty to see directly on the top of the pointer is -1.

// If you want to achieve three stacks in an array, you can divide the array into three parts. If we do not know which stack will load
// more data, it will directly divide the array into three parts, each part of the maintenance of a top pointer, according to which is
// the operation of the stack, with the top of the stack Plus the corresponding offset can be.

#include <iostream>
using namespace std;

class stack3 {
private:
  int *buf;
  int ptop[3];
  int size;

public:
  stack3(int size = 300) {
    buf = new int[size * 3];
    ptop[0] = ptop[1] = ptop[2] = -1;
    this->size = size;
  }

  ~stack3() {
    delete[] buf;
  }

  void push(int stackNum, int val) {
    int idx = stackNum * size + ptop[stackNum] + 1;
    buf[idx] = val;
    ptop[stackNum]++;
  }

  void pop(int stackNum) {
    ptop[stackNum]--;
  }

  int top(int stackNum) {
    int idx = stackNum * size + ptop[stackNum];
    return buf[idx];
  }

  bool empty(int stackNum) {
    return ptop[stackNum] == -1;
  }
};

int main(){
	stack3 mystack;
	for(int i=0; i<10; ++i)
		mystack.push(0, i);
	for(int i=10; i<20; ++i)
		mystack.push(1, i);
	for(int i=100; i<110; ++i)
		mystack.push(2, i);
	for(int i=0; i<3; ++i)
		cout<<mystack.top(i)<<" ";

	cout<<endl;
	for(int i=0; i<3; ++i){
		mystack.pop(i);
		cout<<mystack.top(i)<<" ";
	}
	mystack.push(0, 111);
	mystack.push(1, 222);
	mystack.push(2, 333);
	for(int i=0; i<3; ++i)
		cout<<mystack.top(i)<<" ";
	return 0;
}
