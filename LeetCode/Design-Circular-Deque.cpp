/* Design your implementation of the circular double-ended queue (deque).

Your implementation should support following operations:
>> MyCircularDeque(k): Constructor, set the size of the deque to be k.
>> insertFront(): Adds an item at the front of Deque. Return true if the operation is successful.
>> insertLast(): Adds an item at the rear of Deque. Return true if the operation is successful.
>> deleteFront(): Deletes an item from the front of Deque. Return true if the operation is successful.
>> deleteLast(): Deletes an item from the rear of Deque. Return true if the operation is successful.
>> getFront(): Gets the front item from the Deque. If the deque is empty, return -1.
>> getRear(): Gets the last item from Deque. If the deque is empty, return -1.
>> isEmpty(): Checks whether Deque is empty or not.
>> isFull(): Checks whether Deque is full or not.

Example:
MyCircularDeque circularDeque = new MycircularDeque(3); // set the size to be 3
circularDeque.insertLast(1);			// return true
circularDeque.insertLast(2);			// return true
circularDeque.insertFront(3);			// return true
circularDeque.insertFront(4);			// return false, the queue is full
circularDeque.getRear();  			// return 2
circularDeque.isFull();				// return true
circularDeque.deleteLast();			// return true
circularDeque.insertFront(4);			// return true
circularDeque.getFront();			// return 4
*/

vector<int> buffer;
int cnt;
int k;
int front;
int rear;

/** Initialize your data structure here. Set the size of the deque to be k. */
MyCircularDeque(int k): buffer(k, 0), cnt(0), k(k), front(k - 1), rear(0) {

}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool insertFront(int value) {
  if (cnt == k) {
      return false;
  }
  buffer[front] = value;
  front = (front - 1 + k) % k;
  ++cnt;

  return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool insertLast(int value) {
  if (cnt == k) {
      return false;
  }
  buffer[rear] = value;
  rear = (rear + 1) % k;
  ++cnt;

  return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool deleteFront() {
  if (cnt == 0) {
      return false;
  }
  front = (front + 1) % k;
  --cnt;

  return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool deleteLast() {
  if (cnt == 0) {
      return false;
  }
  rear = (rear - 1 + k) % k;
  --cnt;

  return true;
}

/** Get the front item from the deque. */
int getFront() {
  if (cnt == 0) {
      return -1;
  }
  return buffer[(front + 1) % k];
}

/** Get the last item from the deque. */
int getRear() {
  if (cnt == 0) {
      return -1;
  }
  return buffer[(rear - 1 + k) % k];
}

/** Checks whether the circular deque is empty or not. */
bool isEmpty() {
  return cnt == 0;
}

/** Checks whether the circular deque is full or not. */
bool isFull() {
  return cnt == k;
}
