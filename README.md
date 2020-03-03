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

#### Bubble Sort

- This simple sorting algorithm iterates over a list, comparing elements in pairs and swapping them until the larger elements "bubble up" to the end of the list, and the smaller elements stay at the "bottom".
- [Implementation](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Sorting-in-Python/bubble_sort.py)
- In the worst case scenario (when the list is in reverse order), this algorithm would have to swap every single item of the array. Therefore, if we have n elements in our list, we would have n iterations per item - thus Bubble Sort's time complexity is O(n^2).

![Bubble-Sort](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Sorting-in-Python/Bubble_Sort.gif)

#### Selection Sort

- This algorithm segments the list into two parts: sorted and unsorted. We continuously remove the smallest element of the unsorted segment of the list and append it to the sorted segment.
- [Implementation](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Sorting-in-Python/selection_sort.py)
- For a list with n elements, the outer loop iterates n times. The inner loop iterate n-1 when i is equal to 1, and then n-2 as i is equal to 2 and so forth. The amount of comparisons are `(n - 1) + (n - 2) + ... + 1`, which gives Selection Sort a time complexity of O(n^2).

![Selection-Sort](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Sorting-in-Python/Selection_Sort.gif)

#### Insertion Sort

- Like Selection Sort, this algorithm segments the list into sorted and unsorted parts. It iterates over the unsorted segment, and inserts the element being viewed into the correct position of the sorted list.
- [Implementation](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Sorting-in-Python/insertion_sort.py)
- In the worst case scenario, an array would be sorted in reverse order. The outer for loop in Insertion Sort function always iterates n-1 times. In the worst case scenario, the inner for loop would swap once, then swap two and so forth. The amount of swaps would then be `1 + 2 + ... + (n - 3) + (n - 2) + (n - 1)` which gives Insertion Sort a time complexity of O(n^2).

![Insertion-Sort](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Sorting-in-Python/Insertion_Sort.gif)

#### Heap Sort

- This popular sorting algorithm, like the Insertion and Selection sorts, segments the list into sorted and unsorted parts. It converts the unsorted segment of the list to a Heap data structure, so that we can efficiently determine the largest element.
- [Implementation](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Sorting-in-Python/heap_sort.py)
- Let's first look at the time complexity of the `heapify` function. In the worst case the largest element is never the root element, this causes a recursive call to `heapify`. While recursive calls might seem dauntingly expensive, remember that we're working with a binary tree. Visualize a binary tree with 3 elements, it has a height of 2. Now visualize a binary tree with 7 elements, it has a height of 3. The tree grows logarithmically to n. The `heapify` function traverses that tree in O(log(n)) time.
- The `heap_sort` function iterates over the array n times. Therefore the overall time complexity of the Heap Sort algorithm is O(nlog(n)).

#### Merge Sort

- This divide and conquer algorithm splits a list in half, and keeps splitting the list by 2 until it only has singular elements. Adjacent elements become sorted pairs, then sorted pairs are merged and sorted with other pairs as well. This process continues until we get a sorted list with all the elements of the unsorted input list.
- [Implementation](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Sorting-in-Python/merge_sort.py)
- Let's first look at the `merge` function. It takes two lists, and iterates n times, where n is the size of their combined input.
- The `merge_sort` function splits its given array in 2, and recursively sorts the sub-arrays. As the input being recursed is half of what was given, like binary trees this makes the time it takes to process grow logarithmically to n. Therefore the overall time complexity of the Merge Sort algorithm is O(nlog(n)).

![Merge-Sort](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Sorting-in-Python/Merge_Sort.gif)

#### Quick Sort

- This divide and conquer algorithm is the most often used sorting algorithm. When configured correctly, it's extremely efficient and does not require the extra space Merge Sort uses. We partition the list around a pivot element, sorting values around the pivot.
- [Implementation](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Sorting-in-Python/quick_sort.py)
- The worst case scenario is when the smallest or largest element is always selected as the pivot. This would create partitions of size n-1, causing recursive calls n-1 times. This leads us to a worst case time complexity of O(n^2).
- While this is a terrible worst case, Quick Sort is heavily used because it's average time complexity is much quicker. While the `partition` function utilizes nested while loops, it does comparisons on all elements of the array to make its swaps. As such, it has a time complexity of O(n).
- With a good pivot, the Quick Sort function would partition the array into halves which grows logarithmically with n. Therefore the average time complexity of the Quick Sort algorithm is O(nlog(n)).

![Quick-Sort](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Sorting-in-Python/Quick_Sort.gif)

**Time Complexities of All Sorting Algorithms**

|    Algorithm   | Best Complexity | Average Complexity | Worst Complexity |
|:--------------:|:---------------:|:------------------:|:----------------:|
|   Bubble Sort  |       O(n)      |       O(n^2)       |      O(n^2)      |
| Selection Sort |      O(n^2)     |       O(n^2)       |      O(n^2)      |
| Insertion Sort |       O(n)      |       O(n^2)       |      O(n^2)      |
|    Heap Sort   |    O(n logn)    |      O(n logn)     |     O(n logn)    |
|   Merge Sort   |    O(n logn)    |      O(n logn)     |     O(n logn)    |
|   Quick Sort   |    O(n logn)    |      O(n logn)     |      O(n^2)      |

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

Learn about backtracking in [this video](https://www.youtube.com/watch?v=gBC_Fd8EE8A):
* Backtracking solves problems by trying a series of actions. If a series fails, we back up and try a different series.
* A maze is a classic example, but the approach can be used on a wide variety of problems.
* The recursive solution may be elegant, but remember not to dwell on the backtracking concept or what the recursion is doing.

[back to current section](#algorithms)

### Binary Search

Binary search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing in half the portion of the list that could contain the item, until you've narrowed down the possible locations to just one.

We basically ignore half of the elements just after one comparison.
1. Compare x with the middle element.
2. If x matches with middle element, we return the mid index.
3. Else If x is greater than the mid element, then x can only lie in right half subarray after the mid element. So we recur for right half.
4. Else (x is smaller) recur for the left half.

[Recursive](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Search-in-Python/binary_search_recursive.py) and [Iterative](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Search-in-Python/binary_search_iterative.py) Implementation

![Binary-Search](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Search-in-Python/binary_search_gif.gif)

[back to current section](#algorithms)

### Breadth First Search

Breadth First Search (BFS) is a widely used interview question. Learn about it in [this video](https://www.coursera.org/lecture/algorithms-part2/breadth-first-search-DjaET). It is an algorithm used for tree traversal on graphs or tree data structures. BFS can be easily implemented using recursion and data structures like dictionaries and lists.

**The Algorithm**

1. Pick any node, visit the adjacent unvisited vertex, mark it as visited, display it, and insert it in a queue.
2. If there are no remaining adjacent vertices left, remove the first vertex from the queue.
3. Repeat step 1 and step 2 until the queue is empty or the desired node is found.

- [Implementation](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Search-in-Python/bfs.py )
- Since all of ​the nodes and vertices are visited, the time complexity for BFS on a graph is O(V + E); where V is the number of vertices and E is the number of edges.

[back to current section](#algorithms)

### Depth First Search

Depth First Search (DFS) is a widely used interview question. Learn about it in [this video](https://www.coursera.org/lecture/algorithms-part2/depth-first-search-mW9aG). It is an algorithm for tree traversal on graph or tree data structures. It can be implemented easily using recursion and data structures like dictionaries and arrays.

**The Algorithm**
1. Pick any node. If it is unvisited, mark it as visited and recur on all its adjacent nodes.
2. Repeat until all the nodes are visited, or the node to be searched is found.

- [Implementation](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Search-in-Python/dfs.py)
- Since all of ​the nodes and vertices are visited, the time complexity for DFS on a graph is O(V + E); where V is the number of vertices and E is the number of edges. In case of DFS on a tree, the time complexity is O(V), where V is the number of nodes.

[back to current section](#algorithms)

### Recursion

Learn about recursion in [this video](https://www.coursera.org/lecture/principles-of-computing-2/recursion-ccrwD):
* Used when problems exhibit common sub-structures.
* SumUpTo(n): Base case = 1 when n = 1; Recursive/Inductive case = n + SumUpTo(n - 1) when n > 1

```
def sum_up_to(n):
  if n == 1: return 1
  else: return n + sum_up_to(n - 1)

def is_palindrome(word):
  if len(word) < 2: return True
  else:
    if word[0] != word[-1]: return False
    else: return is_palindrome(word[1:-1])
```

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
