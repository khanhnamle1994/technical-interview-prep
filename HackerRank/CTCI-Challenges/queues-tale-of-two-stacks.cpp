// A queue is an abstract data type that maintains the order in which elements were added to it, allowing the oldest elements to be
// removed from the front and new elements to be added to the rear. This is called a First-In-First-Out (FIFO) data structure because
// the first element added to the queue (i.e., the one that has been waiting the longest) is always the first one to be removed.

/* A basic queue has the following operations:
>> Enqueue: add a new element to the end of the queue.
>> Dequeue: remove the element from the front of the queue and return it.

In this challenge, you must first implement a queue using two stacks. Then process q queries, where each query is one of the following
3 types:
>> 1 x: Enqueue element  into the end of the queue.
>> 2: Dequeue the element at the front of the queue.
>> 3: Print the element at the front of the queue. */

class MyQueue {

    public:
        stack<int> s2, s1;

        void push(int x) {
          while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
          }
        	s2.push(x);
        }

        void pop() {
        	if(s1.empty()) {
        		// Reverse newest stack
        		while(!s2.empty()) {
        			s1.push(s2.top());
        			s2.pop();
        		}
        	}
        	s1.pop();
        }

        int front() {
        	iif(s1.empty()) {
        		// Reverse newest stack
        		while(!s2.empty()) {
        			s1.push(s2.top());
        			s2.pop();
        		}
        	}
        	return s1.top();
        }
};
