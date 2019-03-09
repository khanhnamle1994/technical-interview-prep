/* Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Your implementation should support following operations:
>> MyCircularQueue(k): Constructor, set the size of the queue to be k.
>> Front: Get the front item from the queue. If the queue is empty, return -1.
>> Rear: Get the last item from the queue. If the queue is empty, return -1.
>> enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
>> deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
>> isEmpty(): Checks whether the circular queue is empty or not.
>> isFull(): Checks whether the circular queue is full or not.

Example:
MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
circularQueue.enQueue(1);  // return true
circularQueue.enQueue(2);  // return true
circularQueue.enQueue(3);  // return true
circularQueue.enQueue(4);  // return false, the queue is full
circularQueue.Rear();  // return 3
circularQueue.isFull();  // return true
circularQueue.deQueue();  // return true
circularQueue.enQueue(4);  // return true
circularQueue.Rear();  // return 4
*/

/** Initialize your data structure here. Set the size of the queue to be k. */
vector<int> data;
int head = 0;
int size = 0;
MyCircularQueue(int k) {
    data.resize(k,0);
}


/** Insert an element into the circular queue. Return true if the operation is successful. */
bool enQueue(int value) {
    if(isFull()){
        return false;
    }
    int index = (head+size) % data.size();
    data[index] = value;
    size++;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool deQueue() {
    if(isEmpty()){
        return false;
    }
    head = (head+1)%data.size();
    size--;
    return true;
}

/** Get the front item from the queue. */
int Front() {
    if(isEmpty()){
        return -1;
    }
    return data[head];
}

/** Get the last item from the queue. */
int Rear() {
    if(isEmpty()){
        return -1;
    }
    int index = (head+size+data.size()-1) % data.size();
    return data[index];
}

/** Checks whether the circular queue is empty or not. */
bool isEmpty() {
    return size == 0;
}

/** Checks whether the circular queue is full or not. */
bool isFull() {
    return size == data.size();
}
