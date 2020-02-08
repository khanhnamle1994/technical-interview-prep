# Technical Interview Prep

These are the best online resources that I used while preparing for technical coding interviews:

* [Cracking The Coding Interview](http://www.crackingthecodinginterview.com/): The most popular book on the whole tech interview process, now in 6th edition. 189 programming interview questions are included, ranging from the basics to the trickiest algorithm problems.
* [Elements of Programming Interviews](http://elementsofprogramminginterviews.com/): Another great book written by professional software engineers, with different versions in C++, Java and Python.
* [HackerRank](https://www.hackerrank.com/): A technical recruiting platform that assesses developers based on actual coding skills.
* [Pramp](https://www.pramp.com/): A free online peer-to-peer platform for practicing technical interviews.
* [LeetCode](https://leetcode.com/): One of the best online resource providing a rich library of more than 300 real coding interview questions with 7 supported languages - C, C++, Java, Python, C#, JavaScript, Ruby.
* [Interview Cake](https://www.interviewcake.com/): Another site that preps software engineering candidates for coding interview.

## Algorithms

Here are the algorithms:
* [Sorting](#sorting)
* [Tree Traversals](#tree-traversals)
* [Backtracking](#backtracking)
* [Binary Search](#binary-search)
* [Breadth First Search](#breadth-first-search)
* [Depth First Search](#depth-first-search)
* [Recursion](#recursion)

### Sorting

* **Merge Sort** is a comparison-based algorithm that focuses on how to merge together 2 pre-sorted arrays such that the resulting array is also sorted.
* **Insertion Sort** is a comparison-based algorithm that builds a final sorted array one element at a time. It iterates through an input array and removes one element per iteration, finds the place the element belongs in the array, and then places it there.
* **Bubble Sort** is a comparison​-based algorithm that compares each pair of elements in an array and swaps them if they are out of order until the entire array is sorted. For each element in the list, the algorithm compares every pair of elements.
* **Quick Sort** is a comparison-based algorithm that uses divide-and-conquer to sort an array. The algorithm picks a pivot element, A[q], and then rearranges the array into two subarrays A[p … q − 1], such that all elements are less than A[q], and A[q + 1 … r], such that all elements are greater than or equal to A[q].
* **Heap Sort** is a comparison-based algorithm that uses a binary heap data structure to sort elements. It divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region.
* **Counting Sort** is an integer sorting algorithm that assumes that each of the n input elements in a list has a key value ranging from 0 to k, for some integer k. For each element in the list, counting sort determines the number of elements that are less than it. Counting sort can use this information to place the element directly into the correct slot of the output array.

To choose a sorting algorithm for a particular problem, consider the running time, space complexity, and the expected format of the input list.

|    Algorithm   | Best-case | Worst-case | Average-case | Space Complexity |   Stable?   |
|:--------------:|:---------:|:----------:|:------------:|:----------------:|:-----------:|
|   Merge Sort   |  O(nlogn) |  O(nlogn)  |   O(nlogn)   |       O(n)       |     Yes     |
| Insertion Sort |    O(n)   |   O(n^2)   |    O(n^2)    |       O(1)       |     Yes     |
|   Bubble Sort  |    O(n)   |   O(n^2)   |    O(n^2)    |       O(1)       |     Yes     |
|    Quicksort   |  O(nlogn) |   O(n^2)   |   O(nlogn)   | logn best, n avg | Usually not |
|    Heapsort    |  O(nlogn) |  O(nlogn)  |   O(nlogn)   |       O(1)       |      No     |
|  Counting Sort |   O(k+n)  |   O(k+n)   |    O(k+n)    |      O(k+n)      |     Yes     |

[back to current section](#algorithms)

### Tree Traversals

Tree traversals are commonly used in interviews. Learn about pre-order, in-order and post-order traversal in [this video](https://www.coursera.org/lecture/data-structures/tree-traversal-fr51b).

* Often we want to visit the nodes of a tree in a particular order (for example, print the nodes of the tree)
* Depth-First: We completely traverse one sub-tree before exploring a sibling sub-tree (pre-oder, in-order, post-order).
* Breadth-First: We traverse all nodes at one level before progressing to the next level.
* When working with a tree, recursive algorithms are common.

**Depth-First**

```
InOrderTraversal(tree)

if tree = nil: return
InOrderTraversal(tree.left)
Print(tree.key)
InOrderTraversal(tree.right)
```

```
PreOrderTraversal(tree)

if tree = nil: return
Print(tree.key)
PreOrderTraversal(tree.left)
PreOrderTraversal(tree.right)
```

```
PostOrderTraversal(tree)

if tree = nil: return
PostOrderTraversal(tree.left)
PostOrderTraversal(tree.right)
Print(tree.key)
```

**Breadth-First**

```
LevelTraversal(tree)

if tree = nil: return
Queue q
q.Enqueue(tree)
while not q.Empty():
  node <- q.Dequeue()
  Print(node)
  if node.left != nil:
    q.Enqueue(node.left)
  if node.right != nil:
    q.Enqueue(node.right)
```

[back to current section](#algorithms)

### Backtracking

Learn about backtracking in [this video](https://www.youtube.com/watch?v=gBC_Fd8EE8A).

[back to current section](#algorithms)

### Binary Search

Implementing a binary search is a common interview question. Learn about binary search in [this Khan Academy page](https://www.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search).

[back to current section](#algorithms)

### Breadth First Search

Breadth First Search (BFS) is a widely used interview question. Learn about it in [this video](https://www.coursera.org/lecture/algorithms-part2/breadth-first-search-DjaET).

[back to current section](#algorithms)

### Depth First Search

Depth First Search (DFS) is a widely used interview question. Learn about it in [this video](https://www.coursera.org/lecture/algorithms-part2/depth-first-search-mW9aG).

[back to current section](#algorithms)

### Recursion

Learn about recursion in [this video](https://www.coursera.org/lecture/principles-of-computing-2/recursion-ccrwD).

[back to current section](#algorithms)

[back to top](#technical-interview-prep)

## Data Structures

Here are [the most commonly used data structures](https://www.freecodecamp.org/news/the-top-data-structures-you-should-know-for-your-next-coding-interview-36af0831f5e3/):

1. [Arrays](#arrays)
2. [Stacks](#stacks)
3. [Queues](#queues)
4. [Linked Lists](#linked-lists)
5. [Trees](#trees)
6. [Graphs](#graphs)
7. [Hash Tables](#hash-tables)

### Arrays

An array is the simplest and most widely used data structure. Other data structures like stacks and queues are derived from arrays.

Here’s an image of a simple array of size 4, containing elements (1, 2, 3 and 4).

![array](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/assets/array.png)

Each data element is assigned a positive numerical value called the ≈Index**, which corresponds to the position of that item in the array. The majority of languages define the starting index of the array as 0.

Basic Operations on Arrays:
* Insert — Inserts an element at given index
* Get — Returns the element at given index
* Delete — Deletes an element at given index
* Size — Get the total number of elements in array

Commonly Asked Array Interview Questions:
* Find the second minimum element of an array
* First non-repeating integers in an array
* Merge two sorted arrays
* Rearrange positive and negative values in an array

[back to current section](#data-structures)

### Stacks

A real-life example of Stack could be a pile of books placed in a vertical order. In order to get the book that’s somewhere in the middle, you will need to remove all the books placed on top of it. This is how the LIFO (Last In First Out) method works.

Here’s an image of stack containing three data elements (1, 2 and 3), where 3 is at the top and will be removed first:

![stack](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/assets/stack.png)

Basic Operations of Stack:
* Push — Inserts an element at the top
* Pop — Returns the top element after removing from the stack
* isEmpty — Returns true if the stack is empty
* Top — Returns the top element without removing from the stack

Commonly Asked Stack Interview Questions:
* Evaluate postfix expression using a stack
* Sort values in a stack
* Check balanced parentheses in an expression

[back to current section](#data-structures)

### Queues

Similar to Stack, Queue is another linear data structure that stores the element in a sequential manner. The only significant difference between Stack and Queue is that instead of using the LIFO method, Queue implements the FIFO method, which is short for First in First Out.

A perfect real-life example of Queue: a line of people waiting at a ticket booth. If a new person comes, they will join the line from the end, not from the start — and the person standing at the front will be the first to get the ticket and hence leave the line.

Here’s an image of Queue containing four data elements (1, 2, 3 and 4), where 1 is at the top and will be removed first:

![queue](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/assets/queue.png)

Basic Operations of Queue:
* Enqueue() — Inserts element to the end of the queue
* Dequeue() — Removes an element from the start of the queue
* isEmpty() — Returns true if queue is empty
* Top() — Returns the first element of the queue

Commonly Asked Queue Interview Questions:
* Implement stack using a queue
* Reverse first k elements of a queue
* Generate binary numbers from 1 to n using a queue

[back to current section](#data-structures)

### Linked Lists

A linked list is another important linear data structure which might look similar to arrays at first but differs in memory allocation, internal structure and how basic operations of insertion and deletion are carried out.

A linked list is like a chain of nodes, where each node contains information like data and a pointer to the succeeding node in the chain. There’s a head pointer, which points to the first element of the linked list, and if the list is empty then it simply points to null or nothing.

Linked lists are used to implement file systems, hash tables, and adjacency lists.

Here’s a visual representation of the internal structure of a linked list:

![linked lists](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/assets/linked-lists.png)

Following are the types of linked lists:
* Singly Linked List (Unidirectional)
* Doubly Linked List (Bi-directional)

Basic Operations of Linked List:
* InsertAtEnd — Inserts given element at the end of the linked list
* InsertAtHead — Inserts given element at the start/head of the linked list
* Delete — Deletes given element from the linked list
* DeleteAtHead — Deletes first element of the linked list
* Search — Returns the given element from a linked list
* isEmpty — Returns true if the linked list is empty

Commonly Asked Linked List Interview Questions:
* Reverse a linked list
* Detect loop in a linked list
* Return Nth node from the end in a linked list
* Remove duplicates from a linked list

[back to current section](#data-structures)

### Trees

A tree is a hierarchical data structure consisting of vertices (nodes) and edges that connect them. Trees are similar to graphs, but the key point that differentiates a tree from the graph is that a cycle cannot exist in a tree.

Trees are extensively used in Artificial Intelligence and complex algorithms to provide an efficient storage mechanism for problem-solving.

Here’s an image of a simple tree, and basic terminologies used in tree data structure:

![tree](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/assets/tree.png)

The following are the types of trees:
* N-ary Tree
* Balanced Tree
* Binary Tree
* Binary Search Tree
* AVL Tree
* Red Black Tree
* 2–3 Tree

Out of the above, Binary Tree and Binary Search Tree are the most commonly used trees.

Commonly Asked Tree Interview Questions:
* Find the height of a binary tree
* Find k-th maximum value in a binary search tree
* Find nodes at “k” distance from the root
* Find ancestors of a given node in a binary tree

[back to current section](#data-structures)

### Graphs

A graph is a set of nodes that are connected to each other in the form of a network. Nodes are also called vertices. A **pair(x,y)** is called an **edge**, which indicates that vertex **x** is connected to vertex **y**. An edge may contain weight/cost, showing how much cost is required to traverse from vertex x to y.

![graph](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/assets/graph.png)

Types of Graphs:
* Undirected Graph
* Directed Graph

In a programming language, graphs can be represented using two forms:
* Adjacency Matrix
* Adjacency List

Common Graph Traversing Algorithms:
* Breadth First Search
* Depth First Search

Commonly Asked Graph Interview Questions:
* Implement Breadth and Depth First Search
* Check if a graph is a tree or not
* Count number of edges in a graph
* Find the shortest path between two vertices

[back to current section](#data-structures)

### Hash Tables

Hashing is a process used to uniquely identify objects and store each object at some pre-calculated unique index called its “key.” So, the object is stored in the form of a “key-value” pair, and the collection of such items is called a “dictionary.” Each object can be searched using that key. There are different data structures based on hashing, but the most commonly used data structure is the **hash table**.

Hash tables are generally implemented using arrays.

The performance of hashing data structure depends upon these three factors:
* Hash Function
* Size of the Hash Table
* Collision Handling Method

Here’s an illustration of how the hash is mapped in an array. The index of this array is calculated through a Hash Function.

![hash table](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/assets/hash-table.png)

Commonly Asked Hashing Interview Questions:
* Find symmetric pairs in an array
* Trace complete path of a journey
* Find if an array is a subset of another array
* Check if given arrays are disjoint

[back to current section](#data-structures)

[back to top](#technical-interview-prep)

## Reading Code

As an engineer or scientist, significant time is spent reading code others have written. Our advice for you to understand code written by others is to read a lot of code and try to figure out its goal.

Here are [the tips for reading code](https://wiki.c2.com/?TipsForReadingCode):
1. Build and Run the Program
2. Find the High-Level Logic
3. Draw Some Flowchart
4. Examine Library Calls
5. Search for Key Words
6. Leverage the Power of Code Comprehension Tools
7. Print the Code
8. Write Unit Tests
9. Comment the Code
10. Clean up the Code
