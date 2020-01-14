## Technical Interview Prep

These are the best online resources that I used while preparing for technical coding interviews:

* [Cracking The Coding Interview](http://www.crackingthecodinginterview.com/): The most popular book on the whole tech interview process, now in 6th edition. 189 programming interview questions are included, ranging from the basics to the trickiest algorithm problems.
* [Elements of Programming Interviews](http://elementsofprogramminginterviews.com/): Another great book written by professional software engineers, with different versions in C++, Java and Python.
* [HackerRank](https://www.hackerrank.com/): A technical recruiting platform that assesses developers based on actual coding skills.
* [Pramp](https://www.pramp.com/): A free online peer-to-peer platform for practicing technical interviews.
* [LeetCode](https://leetcode.com/): One of the best online resource providing a rich library of more than 300 real coding interview questions with 7 supported languages - C, C++, Java, Python, C#, JavaScript, Ruby.
* [Interview Cake](https://www.interviewcake.com/): Another site that preps software engineering candidates for coding interview.

## Sorting Algorithms

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

## Tree

Review the [tree](https://www.coursera.org/lecture/data-structures/trees-95qda) data structure.

## Tree Traversals

Tree traversals are commonly used in interviews. Learn about pre-order, in-order and post-order traversal in [this video](https://www.coursera.org/lecture/data-structures/tree-traversal-fr51b).

## Backtracking

Learn about backtracking in [this video](https://www.youtube.com/watch?v=gBC_Fd8EE8A).

## Binary Search

Implementing a binary search is a common interview question. Learn about binary search in [this Khan Academy page](https://www.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search).

## Breadth First Search

Breadth First Search (BFS) is a widely used interview question. Learn about it in [this video](https://www.coursera.org/lecture/algorithms-part2/breadth-first-search-DjaET).

## Depth First Search

Depth First Search (DFS) is a widely used interview question. Learn about it in [this video](https://www.coursera.org/lecture/algorithms-part2/depth-first-search-mW9aG).

## Recursion

Learn about recursion in [this video](https://www.coursera.org/lecture/principles-of-computing-2/recursion-ccrwD).

## Reading Code

As an engineer or scientist, significant time is spent reading code others have written. Our advice for you to understand code written by others is to read a lot of code and try to figure out its goal. You can find tips for reading code in [this page](https://wiki.c2.com/?TipsForReadingCode). Also, you can find some advice on how to quickly read other people's code [here](https://selftaughtcoders.com/how-to-quickly-and-effectively-read-other-peoples-code/).
