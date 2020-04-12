# Technical Interview Prep

Here are the sections:
* [How to Succeed in Data Structures and Algorithms Interview](#how-to-succeed-in-data-structures-and-algorithms-interview)
* [Algorithms](#algorithms)
* [Data Structures](#data-structures)
* [Curated LeetCode Questions](#curated-leetcode-questions)
* [Software Engineering](#software-engineering)

These are the best online resources that I used while preparing for technical coding interviews:

* [Cracking The Coding Interview](http://www.crackingthecodinginterview.com/): The most popular book on the whole tech interview process, now in 6th edition. 189 programming interview questions are included, ranging from the basics to the trickiest algorithm problems.
* [Elements of Programming Interviews](http://elementsofprogramminginterviews.com/): Another great book written by professional software engineers, with different versions in C++, Java and Python.
* [HackerRank](https://www.hackerrank.com/): A technical recruiting platform that assesses developers based on actual coding skills.
* [Pramp](https://www.pramp.com/): A free online peer-to-peer platform for practicing technical interviews.
* [LeetCode](https://leetcode.com/): One of the best online resource providing a rich library of more than 300 real coding interview questions with 7 supported languages - C, C++, Java, Python, C#, JavaScript, Ruby.
* [Interview Cake](https://www.interviewcake.com/): Another site that preps software engineering candidates for coding interview.

## How to Succeed in Data Structures and Algorithms Interview

* [Preparation](#preparation)
* [Understand the Problem](#understand-the-problem)
* [Brute Force Solution](#brute-force-solution)
* [Optimize Your Solution](#optimize-your-solution)
* [Code Your Solution](#code-your-solution)
* [Test Your Solution](#test-your-solution)

### Preparation

* **Develop a deep knowledge of data structures**: You should understand and be able to talk about different data structures and their strengths, weaknesses, and how they compare to each other. Taking the time to implement data structures from scratch will leave you much better prepared for DS&A interviews, than studying them as an abstract concept.
* **Understand Big O notation**: You should be able to talk about Big O notation for both time and space complexity. Make sure to read about common algorithms and their memory and runtime complexity to train your big O analysis muscle.
* **Know the major sorting algorithms**: Given that differences in time and space complexity can derail your optimal solution for an algorithm problem, it’s good to be familiar with the major algorithms per category (string matching, sorting, search, graph, traversal, etc).

[back to current section](#how-to-succeed-in-data-structures-and-algorithms-interview)

### Understand the Problem

* To verify your understanding, repeat the question back to the interviewer in your own words to make sure you got it correctly. There’s nothing worse than realizing mid-interview that you’re answering a completely different question. It could be helpful to use a test or two to verify your understanding of the problem.
* You should feel comfortable asking your interviewer questions to define any ambiguities and ask them if you can make certain assumptions (e.g. “Can I assume the array is sorted?” or “Can I assume the input is valid?”). Remember that the interviewer’s goal is to get a good signal for how you think through an issue or problem.
* You may consider asking them the following questions:
  - How large is the range of values? What kind of values exists?
  - How large is the size of the input? Are there duplicates within the input?
  - What are some extreme cases of inputs?
  - How is the input stored?
* You should also ask whether you’ll eventually be optimizing for time, space, or both. Even if you believe you already know how to solve the problem, it’s important to ensure that you’re spending your time implementing the solution that your interviewer cares about.
* Keep track of how much time you’re spending in the ideation phase to leave yourself enough time to code your solution.

[back to current section](#how-to-succeed-in-data-structures-and-algorithms-interview)

### Brute Force Solution

* The worst outcome in a technical interview is to not write any code, and the easiest way to end up in that position is to overcomplicate the problem early in the interview.
* Instead, talk through a solution you’re confident will work and let your interviewer know about the concessions you’ve made. You might think that if you present an initial suboptimal solution that you’ll never get hired, but this isn’t true. Communication is important here. You can score points with your interviewer by explaining the time and space complexity of your naive or brute-force solution and by clarifying why it’s suboptimal; you’ll have the chance to improve it later.
* Now that you’ve talked through the brute-force solution, ask the interviewer whether they’d like you to implement the brute force solution or come up with a more efficient solution. If the former, skip the next section “Optimize your Solution” and come back to it at the end. Only start coding once you and your interviewer have agreed on an approach and they’ve given you the green light to move ahead.

[back to current section](#how-to-succeed-in-data-structures-and-algorithms-interview)

### Optimize Your Solution

* Discuss your approach with your interviewer and lean on them to get a sense of whether they have a preference for whether you optimize for time, space, or both. When optimizing, some of your initial assumptions may change, so it’s important to check with your interviewer.
* You may see the most optimal solution right away or be unsure on how to proceed. If you’re stuck, here are some common approaches to optimizing:
  - Take a second look at the problem, its constraints, and write down your assumptions and possible simplifications.
  - Consider similar problems you’ve seen and discuss them with your interviewer.
  - Solve an example by hand and extrapolate about what algorithm(s) could be used.
  - Simulate the brute-force solution by hand and identify the inefficiencies that could be optimized with a data structure.
  - Solve a simple version of the problem first, then build on it.
* Don’t forget to communicate and analyze the time or space complexity of the solution you plan to optimize. Once you and your interviewer agree that you have a good solution, it’s time to code it.

[back to current section](#how-to-succeed-in-data-structures-and-algorithms-interview)

### Code Your Solution

* As an interviewee, it’s important to ensure that your interviewer understands what you’re doing and why you’re doing it in real-time. If you’re explaining your thought process out loud and you take a wrong turn, your interviewer may offer you a hint to get you back on track.
* While you’re coding, don’t read your code verbatim; but rather, talk about the section of the code you’re implementing at a higher level. Explain why you wrote it that way and what it’s trying to achieve.
* Remember that your interviewer needs to be able to understand your code to efficiently evaluate whether your code returns the expected result and solves the problem. As you code, keep these pointers in mind:
  - Use good style when writing your code.
  - Naming Matters.
  - Demonstrate good modularity.
  - Leave time to check for bugs and edge cases.
  - If cutting corners, explain it to your interviewer.
* Take a step back and briefly read through your solution, examining it as if it were written by someone else, but don’t start debugging it manually. This is the same approach that will be taken by your interviewer. Fix any issues you may find.
* Then walk your interviewer through the code and explain your rationale. If you find a bug or mistake, feel free to acknowledge it and make the change.

[back to current section](#how-to-succeed-in-data-structures-and-algorithms-interview)

### Test Your Solution

* During the testing portion of the interview, you should have a few goals in mind. You want to…
  - Demonstrate that you care that your code actually works.
  - Show that you can understand and solve problems even if it doesn’t work.
  - Exhibit your understanding of the various edge cases that a real-world problem might present.
  - Establish a feedback loop for your code that allows refactoring without having to worry about breaking existing functionality.
* There are a few types of inputs you’re going to test for:
  - Large and small valid inputs.
  - Large and small invalid inputs.
  - Random input.
* For each input, manually go through your code and ensure that it performs. You should jot down or tell your interviewer the values of each variable as you walk them through the code.
* If you find an error, explain the error to your interviewer, fix it, and move on. Similarly, if there are large duplicated code blocks in your solution, you can take the time to restructure the code.
* In this stage, you’ll also have the opportunity to showcase your knowledge around automated testing. You can chat about how you’d generate different types of inputs, how you would stub parts of the code, the test runners you’d use, and more. These are all great signals to show an interviewer.

[back to current section](#how-to-succeed-in-data-structures-and-algorithms-interview)

[back to top](#technical-interview-prep)

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
* **Insert** — Inserts an element at given index: O(n)
* **Get** — Returns the element at given index: O(n)
* **Delete** — Deletes an element at given index: O(n)
* **Size** — Get the total number of elements in array: O(1)

**Commonly Asked Array Interview Questions**:
1. Find the second minimum element of an array

  - A **simple solution** is to sort the array in increasing order. The first 2 elements in sorted array would be 2 smallest elements. Time complexity is O(n logn).
  - A **better solution** is to scan the array twice. In 1st traversal, find the minimum element. Let this element be x. In 2nd traversal, find the smallest element greater than x. Time complexity of this solution is O(n).
  - An **efficient solution** can find the minimum 2 elements in one traversal.

  ```
  1> Initialize both first and second smallest as INT_MAX
  2> Loop through all elements:
    a> If the current element is smaller than the first, then update first and second.
    b> Else if the current element is smaller than second, then update second.
  ```

2. Find the first non-repeating element in an array of integers

  - A **simple solution** is to use 2 loops. The outer loop picks elements one by one and inner loop checks if the element is present more than once or not.
  - An **efficient solution** is to use hashing: (1) Traverse array and insert elements and their counts in a hash table. (2) Traverse array again and print first element with count equals to 1.
  - **Further optimization**: If array has many duplicates, we can also store index in hash table, using a hash table where value is a pair. Now we only need to traverse keys in hash table to find first non-repeating.

3. Merge two sorted arrays

  - The idea is to use **Merge** function of **Merge sort** - O(n1 + n2) time and O(n1 + n2) space
    - Create a new array arr3[] of size n1 + n2.
    - Simultaneously traverse arr1[] and arr2[]
      - Pick smaller of current elements in arr1[] and arr2[], copy this smaller element to next position in arr3[] and move ahead in arr3[] and the array whose element is picked.
    - If there are remaining elements in arr1[] or arr2[], copy them also in arr3[].

![merge-sorted-arrays](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/assets/Merge-two-sorted-arrays.png)

[back to current section](#data-structures)

### Stacks

A real-life example of Stack could be a pile of books placed in a vertical order. In order to get the book that’s somewhere in the middle, you will need to remove all the books placed on top of it. This is how the LIFO (Last In First Out) method works.

Here’s an image of stack containing three data elements (1, 2 and 3), where 3 is at the top and will be removed first:

![stack](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/assets/stack.png)

Basic Operations of Stack:
* **Push** — Inserts an element at the top: O(1)
* **Pop** — Returns the top element after removing from the stack: O(1)
* **isEmpty** — Returns true if the stack is empty: O(1)
* **Top** — Returns the top element without removing from the stack: O(1)

```
class Stack:

    def __init__(self):
        self.stack = []

    def add(self, dataval):
        # Use list append method to add element
        if dataval not in self.stack:
            self.stack.append(dataval)
            return True
        else:
            return False

    def peek(self):
        # Use peek to look at the top of the stack
	       return self.stack[-1]

    def remove(self):
        # Use list pop method to remove element
        if len(self.stack) <= 0:
            return ("No element in the Stack")
        else:
            return self.stack.pop()
```

**Commonly Asked Stack Interview Questions**:
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
* **Enqueue()** — Inserts element to the end of the queue: O(1)
* **Dequeue()** — Removes an element from the start of the queue: O(1)
* **isEmpty()** — Returns true if queue is empty: O(1)
* **Top()** — Returns the first element of the queue: O(1)

A queue can be implemented using python list where we can use the insert() and pop() methods to add and remove elements. Their is no insertion as data elements are always added at the end of the queue.

```
class Queue:

    def __init__(self):
        self.queue = list()

    def addtoq(self,dataval):
        # Insert method to add element
        if dataval not in self.queue:
            self.queue.insert(0,dataval)
            return True
        return False

    def size(self):
        return len(self.queue)

    # Pop method to remove element
    def removefromq(self):
        if len(self.queue)>0:
            return self.queue.pop()
        return ("No elements in Queue!")
```

**Commonly Asked Queue Interview Questions**:
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
* **InsertAtEnd** — Inserts given element at the end of the linked list: O(1)
* **InsertAtHead** — Inserts given element at the start/head of the linked list: O(1)
* **Delete** — Deletes given element from the linked list: O(1)
* **DeleteAtHead** — Deletes first element of the linked list: O(1)
* **Search** — Returns the given element from a linked list: O(n)
* **isEmpty** — Returns true if the linked list is empty: O(1)

**Commonly Asked Linked List Interview Questions**:
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

A **binary tree** is a non linear data structure where each node can have at most 2 child nodes.
![](assets/binary-tree.png)
- If a node have 0 child nodes then it is called a leaf node. In the above image {2,5,11,4} are the leaf nodes.
- The worst case complexity for searching a node is O(n).

**Binary search tree** is a binary tree in which a node have a value greater than all values in its left subtree and smaller than all values in its right subtree.
![](assets/binary-search-tree.png)
- If a Binary search tree is balanced then you can find a value in O(log n) time.
- Let's say we want to find node 12:
  - We will start from the root node which in this case is 15.
  - Current node is 15, but 12<15 , we go in the left subtree because right subtree has even greater values.
  - Current node is 10, but 12>10 , we go in the right subtree because left subtree has even smaller values.
  - Current node is 12. BOOM!

**Commonly Asked Tree Interview Questions**:
1. Find the height of a binary tree

Recursively calculate the height of left and right subtrees of a node and assign the height to the node as max of the heights of 2 children plus 1.

```
1 - If tree is empty, then return 0
2 - Else
  (a) Get the max depth of left subtree recursively
  (b) Get the max depth of right subtree recursively
  (c) Get the max of max depths of left and right subtrees and add 1 to it for the current node
  (d) Return max_depth
```

2. Find nodes at “k” distance from the root

```
def printKDistance(root, k):
  if root is None: return
  if k == 0:
    print(root.data)
  else:
    printKDistance(root.left, k - 1)
    printKDistance(root.right, k - 1)
```

3. Find ancestors of a given node in a binary tree

```
def printAncestors(root, target):

  # Base case
  if root == None: return False
  if root.data == target: return True

  # If target is present in either left or right subtree of this node, then print this node
  if (printAncestors(root.left, target) or printAncestors(root.right, target)):
    print(root.data)
    return True

  return False
```

[back to current section](#data-structures)

### Graphs

A graph is a set of nodes that are connected to each other in the form of a network. Nodes are also called vertices. A **pair(x,y)** is called an **edge**, which indicates that vertex **x** is connected to vertex **y**. An edge may contain weight/cost, showing how much cost is required to traverse from vertex x to y.

![graph](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/assets/graph.png)

- Types of Graphs: Undirected Graph and Directed Graph
- In a programming language, graphs can be represented using two forms: Adjacency Matrix and Adjacency List
- Common Graph Traversing Algorithms: Breadth First Search and Depth First Search

A graph can be easily presented using the python dictionary data types. We represent the vertices as the keys of the dictionary and the connection between the vertices also called edges as the values in the dictionary. Here are basic operations:
* To **display graph vertices**, we simple find the keys of the graph dictionary. We use the keys() method.
* To **find graph edges**, we have to find each of the pairs of vertices which have an edge in between them. So we create an empty list of edges then iterate through the edge values associated with each of the vertices. A list is formed containing the distinct group of edges found from the vertices.
* To **add a vertex**, we add another additional key to the graph dictionary.
* To **add an edge** to an existing graph, we treat the new vertex as a tuple and validating if the edge is already present. If not then the edge is added.

Take a look at the following graph:

![graph basics](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/assets/graph_basics.jpg)

In the above graph:

```
V = {a, b, c, d, e}
E = {ab, ac, bd, cd, de}
```

```
class graph:
    def __init__(self,gdict=None):
        if gdict is None:
            gdict = []
        self.gdict = gdict

    # Get the keys of the dictionary
    def getVertices(self):
        return list(self.gdict.keys())

    def edges(self):
        return self.findedges()

    # Find the distinct list of edges
    def findedges(self):
        edgename = []
        for vrtx in self.gdict:
            for nxtvrtx in self.gdict[vrtx]:
                if {nxtvrtx, vrtx} not in edgename:
                    edgename.append({vrtx, nxtvrtx})
        return edgename

    # Add the vertex as a key
    def addVertex(self, vrtx):
           if vrtx not in self.gdict:
                self.gdict[vrtx] = []

    # Add the new edge
    def AddEdge(self, edge):
        edge = set(edge)
        (vrtx1, vrtx2) = tuple(edge)
        if vrtx1 in self.gdict:
            self.gdict[vrtx1].append(vrtx2)
        else:
            self.gdict[vrtx1] = [vrtx2]

# Create the dictionary with graph elements
graph_elements = { "a" : ["b","c"],
                "b" : ["a", "d"],
                "c" : ["a", "d"],
                "d" : ["e"],
                "e" : ["d"]
                }

g = graph(graph_elements)
```

**Commonly Asked Graph Interview Questions**:
* Implement Breadth and Depth First Search:
  - [BFS](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Search-in-Python/bfs.py)
  - [DFS](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/Search-in-Python/dfs.py)
* Check if a graph is a tree or not
* Count number of edges in a graph
* Find the shortest path between two vertices

[back to current section](#data-structures)

### Hash Tables

Hashing is a process used to uniquely identify objects and store each object at some pre-calculated unique index called its “key.” So, the object is stored in the form of a “key-value” pair, and the collection of such items is called a “dictionary.” Each object can be searched using that key. There are different data structures based on hashing, but the most commonly used data structure is the **hash table**.

Hash tables are generally implemented using arrays. Its search, insert, and delete operations all take O(1) average complexity and O(n) worst complexity.

The performance of hashing data structure depends upon these three factors:
* Hash Function: A function that maps a big number or string to a small integer that can be used as the index in the hash table.
* Size of the Hash Table: Changing the size of the hash table will change the compression function, leading to the keys being allotted to different buckets.
* Collision Handling Method: Hash function may return the same hash value for 2 or more keys (collision). We can resolve this problem either via separate chaining or open addressing.

Here’s an illustration of how the hash is mapped in an array. The index of this array is calculated through a Hash Function.

![hash table](https://github.com/khanhnamle1994/technical-interview-prep/blob/master/assets/hash-table.png)

In Python, the Dictionary data types represent the implementation of hash tables. Here are basic operations:
* To **access** dictionary elements, you can use the familiar square brackets along with the key to obtain its value.
* You can *update* a dictionary by adding a new entry or a key-value pair, modifying an existing entry, or deleting an existing entry.
* You can either remove individual dictionary elements or clear the entire contents of a dictionary. You can also **delete** entire dictionary in a single operation. To explicitly remove an entire dictionary, just use the `del` statement.

```
# Declare a dictionary
dict = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}

# Accessing the dictionary with its key
print "dict['Name']: ", dict['Name']
print "dict['Age']: ", dict['Age']

dict['Age'] = 8; # update existing entry
dict['School'] = "DPS School"; # Add new entry

del dict['Name']; # remove entry with key 'Name'
dict.clear();     # remove all entries in dict
del dict ;        # delete entire dictionary
```

**Commonly Asked Hashing Interview Questions**:
* Find symmetric pairs in an array
* Trace complete path of a journey
* Find if an array is a subset of another array
* Check if given arrays are disjoint

[back to current section](#data-structures)

[back to top](#technical-interview-prep)

## Curated LeetCode Questions

### Array
- [Two Sum](https://leetcode.com/problems/two-sum/)
- [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
- [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

### Graph
- [Number of Islands](https://leetcode.com/problems/number-of-islands/)

### String
- [Valid Anagram](https://leetcode.com/problems/valid-anagram/)
- [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/submissions/)
- [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
- [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
- [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/)

### Tree
- [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
- [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)
- [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

[back to top](#technical-interview-prep)

## Software Engineering

* [Understanding race conditions](#understanding-race-conditions)
* [Understanding the difference between concurrency and parallelism](#understanding-the-difference-between-concurrency-and-parallelism)
* [Analyzing large files](#analyzing-large-files)
* [Differentiate the stack from the heap](#differentiate-the-stack-from-the-heap)
* [Making good software design decisions](#making-good-software-design-decisions)
* [Differentiating Monolithic vs Microservices architectures](#differentiating-monolithic-vs-microservices-architectures)
* [Understanding the role of the Hostname in a request](#understanding-the-role-of-the-hostname-in-a-request)
* [Understanding classes and inheritance](#understanding-classes-and-inheritance)
* [Understanding the purpose of different HTTP requests](#understanding-the-purpose-of-different-HTTP-requests)
* [Understanding the single responsibility principle](#understanding-the-single-responsibility-principle)
* [Understanding the benefits of continuous integration](#understanding-the-benefits-of-continous-integration)

### Understanding race conditions

Race conditions affect the correctness of concurrent programs. Learn about race conditions and the related concept of interleaving in [this video](https://www.coursera.org/lecture/golang-concurrency/m2-2-1-2v3-dybTl). You can also read about race conditions in [this MIT page](https://web.mit.edu/6.005/www/fa15/classes/19-concurrency/#race_condition).

- A **race condition** means that the correctness of the program (the satisfaction of postconditions and invariants) depends on the relative timing of events in concurrent computations A and B. When this happens, we say “A is in a race with B.”
- Some inter-leavings of events may be OK, in the sense that they are consistent with what a single, non-concurrent process would produce, but other inter-leavings produce wrong answers – violating postconditions or invariants.

[back to top](#software-engineering)

### Understanding the difference between concurrency and parallelism

Concurrency and parallelism are fundamental concepts in software engineering. Learn about the differences between these two concepts in [this video](https://www.coursera.org/lecture/parprog1/introduction-to-parallel-computing-zNrIS) (minute 6:32). You can read about concurrency in [this Wikipedia article](https://en.wikipedia.org/wiki/Concurrent_computing) and [this MIT page](https://web.mit.edu/6.005/www/fa14/classes/17-concurrency/#reading_17_concurrency). Also, you can read about parallelism in [this Wikipedia article](https://en.wikipedia.org/wiki/Parallel_computing).

- **Parallelism** is a type of computation in which many calculations are performed at the same time.
  - Basic principle: computation can be divided into smaller subproblems, each of which can be solved simultaneously.
  - Assumption: we have parallel hardware at our disposal, which is capable of executing these computations in parallel.

- Why Parallelism?
  - Parallel programming is much harder than sequential programming. Separating sequential computations into parallel subcomputations can be challenging, or even impossible.
  - Ensuring program correctness is more difficult, due to new types of errors.
  - *Speedup* is the only reason why we bother paying for this complexity.

- **Concurrency** means multiple computations are happening at the same time. Concurrency is everywhere in modern programming, whether we like it or not:
  - (1) Multiple computers in a network,
  - (2) Multiple applications running on one computer,
  - (3) Multiple processors in a computer (today, often multiple processor cores on a single chip)
- In fact, concurrency is essential in modern programming:
  - Web sites must handle multiple simultaneous users.
  - Mobile apps need to do some of their processing on servers (“in the cloud”).
  - Graphical user interfaces almost always require background work that does not interrupt the user. For example, Eclipse compiles your Java code while you’re still editing it.

Parallelism and concurrency are closely related concepts:
- Parallel program uses parallel hardware to execute computation more quickly. Efficiency is its main concern.
- Concurrent program may or may not execute multiple executions at the same time. Improves modularity, responsiveness or maintainability.

[back to top](#software-engineering)

### Analyzing large files

Quickly analyzing large structured files is often difficult to do on standard spreadsheet applications. Therefore, it is useful to know how to use the Linux shell to perform such tasks. Read about useful shell commands for data handling in [this DataCamp page](https://www.datacamp.com/community/tutorials/shell-commands-data-scientist).

- Count with `wc`.
- Concatenate files with `cat`.
- Modify a file with `sed`.
- Subset a large file with `head` and `tail`.
- Finding duplicates with `uniq`.
- Selecting columns with `cut`.
- Looping with `while true; do ... done` to process or transfer large number of files.
- Create variables with `varname`.

[back to top](#software-engineering)

### Differentiate the stack from the heap

The stack is the memory set aside as scratch space for a thread of execution. The heap is memory set aside for dynamic allocation. Read [this thread](https://stackoverflow.com/questions/79923/what-and-where-are-the-stack-and-heap#comment67326550_80113) for more information.

- The **stack** is the memory set aside as scratch space for a thread of execution.
  - When a function is called, a block is reserved on the top of the stack for local variables and some bookkeeping data. When that function returns, the block becomes unused and can be used the next time a function is called.
  - The stack is always reserved in a LIFO (last in first out) order; the most recently reserved block is always the next block to be freed. This makes it really simple to keep track of the stack; freeing a block from the stack is nothing more than adjusting one pointer.
- The **heap** is memory set aside for dynamic allocation.
  - Unlike the stack, there's no enforced pattern to the allocation and deallocation of blocks from the heap; you can allocate a block at any time and free it at any time.
  - This makes it much more complex to keep track of which parts of the heap are allocated or free at any given time; there are many custom heap allocators available to tune heap performance for different usage patterns.
- Each thread gets a stack, while there's typically only one heap for the application (although it isn't uncommon to have multiple heaps for different types of allocation).

- *To what extent are they controlled by the OS or language runtime?*
  - The OS allocates the stack for each system-level thread when the thread is created.
  - Typically the OS is called by the language runtime to allocate the heap for the application.
- *What is their scope?*
  - The stack is attached to a thread, so when the thread exits the stack is reclaimed.
  - The heap is typically allocated at application startup by the runtime, and is reclaimed when the application (technically process) exits.
- *What determines the size of each of them?*
  - The size of the stack is set when a thread is created.
  - The size of the heap is set on application startup, but can grow as space is needed (the allocator requests more memory from the operating system).
- *What makes one faster?*
  - The stack is faster because the access pattern makes it trivial to allocate and deallocate memory from it (a pointer/integer is simply incremented or decremented), while the heap has much more complex bookkeeping involved in an allocation or deallocation.
  - Also, each byte in the stack tends to be reused very frequently which means it tends to be mapped to the processor's cache, making it very fast.
  - Another performance hit for the heap is that the heap, being mostly a global resource, typically has to be multi-threading safe, i.e. each allocation and deallocation needs to be - typically - synchronized with "all" other heap accesses in the program.

[back to top](#software-engineering)

### Making good software design decisions

When building software applications, it is important to make good design decisions. To practice your software design, review [this interview preparation document](https://workera.ai/candidates/interview_prep/#h.dxekc5ol5li).

### Differentiating Monolithic vs Microservices architectures

Review a comparison between monolithic and microservices applications in [this video](https://www.coursera.org/lecture/uva-darden-continous-delivery-devops/microservices-vs-monoliths-tTnKW).

### Understanding the role of the Hostname in a request

Review the role and definition of a hostname in [this wikipedia page](https://en.wikipedia.org/wiki/Hostname).

### Understanding classes and inheritance

Learn about classes in [this video](https://www.coursera.org/lecture/python-databases/14-2-our-first-class-and-object-MI9uq). Learn about inheritance in [this video](https://www.coursera.org/lecture/intermediate-object-oriented-programming-unity-games/what-is-inheritance-Z2t3M).

### Understanding the purpose of different HTTP requests

Review the purpose of different HTTP requests (also known as methods or verbs) in [this Mozilla Web Docs page](https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods).

### Understanding the single responsibility principle

The SOLID principles of Object-Oriented Design are guidelines for writing clean code. You can learn more about the single responsibility principle in [this Wikipedia article](https://en.wikipedia.org/wiki/Single_responsibility_principle). Also, you can find a more elaborate explanation of this principle in [this blog post](https://blog.cleancoder.com/uncle-bob/2014/05/08/SingleReponsibilityPrinciple.html).

### Understanding the benefits of continuous integration

Continuous integration is one of the strategies to increase development speed and reduce time to market. Review the concept of continuous integration in [this video](https://www.coursera.org/lecture/devops-culture-and-mindset/configuration-management-continuous-integration-testing-and-delivery-8YCtX) (min 2:59). If you prefer reading, you can check [this Wikipedia article](https://en.wikipedia.org/wiki/Continuous_integration).

[back to top](#technical-interview-prep)
