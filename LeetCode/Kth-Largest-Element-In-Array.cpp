// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
// For example, given [3,2,1,5,6,4] and k = 2, return 5.

/* Analysis:
In this problem, we utilize array to represent heap, literally heap is a Tree structure, which has the following property: The value of
parent node is greater/smaller than that of its children.
(Be careful with the definition, it has no constrains about the child nodes in the same level)

Before we start to construct heap, firstly let's review the tree representation using array. Simply, let's use a vector<int> to define
a binary tree A, where the value of node is type int. Then let's define the tree structure:
(1) Every element is used to represent a tree node.
(2) The root node is defined as the 1st element of A, A[0].
(3) For each node A[i], its left child is A[i*2+1], its right child is A[i*2+2].
(4) For each node A[i], its parent node is A[(i-2)/2], when (i-2)/2 >=0

This is not a very complete definition, but enough for our heap implementation. Now we construct the heap, as well as heap sort algorithm.

The most important step in the algorithm is called "downshift". This downshift operation, takes the root node of the binary tree, compare
to its left and right children, swap the value with the greater/smaller child, recursively.  This can be implemented as a standalone function.

Since the tree leaves has no child node, so the leaf nodes are left without any downshift operation. To construct the heap, we can
downshift all the non-leaf nodes, from bottom to top. After this loop, the tree is now called a heap.

In order to get the heap sort result (which is usually an array), one more operation is needed. Currently the heap is a binary tree, to
get the sorted array, every time we take the root node (which is biggest/smallest element), and then swap the root node with the last
node in the tree. (Remember we have used an array to represent a tree?) , then apply downshift of the root node, to keep the tree as a
heap. */

class Solution {
public:
    void downshift(vector<int> &h, int n, int parent){
        if (parent < 0){return;}
        int left = parent*2+1;
        int right = parent*2+2;
        int mxch;
        if (left>=n) {return;}
        if (right>=n){mxch=left;}
        else{
            mxch = h[left]>=h[right]?left:right;
        }
        if (h[parent]<h[mxch]){
            int tmp = h[parent];
            h[parent] = h[mxch];
            h[mxch] = tmp;
            downshift(h,n,mxch);
        }
    }


    void constructHeap(vector<int>& h, int n){
        int parent = (n-2/2);
        for (; parent>=0;parent--){
            downshift(h, n, parent);
        }
    }

    void heapsort(vector<int> &h, int n){
        constructHeap(h,n);
        int i=n-1;
        vector<int> b(n,0);
        while (i>=0){
            b[n-i-1]=h[0];
            int tmp = h[0];
            h[0] = h[i];
            h[i] = tmp;
            downshift(h,i,0);
            i--;
        }
        for (int i=0;i<n;i++){
            h[i] = b[i];
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        heapsort(nums,nums.size());
        return nums[k-1];
    }
};
