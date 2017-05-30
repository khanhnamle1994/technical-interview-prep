// Write a program that takes two cycle-free singly linked lists, and determines if there exists a node that is common to both lists

/* Solution:
A brute-force approach is to store one list's nodes in a hash table, and then iterate through the nodes of the other, testing each for
presence in the hash table. This takes O(n) time and O(n) space, where n is the total number of nodes.

We can avoid extra space by using 2 nested loops, one iterating through the first list, and the other to search the second for the node
being processed in the first list. However, the time complexity is O(n^2).

The lists overlap if and only if both have the same tail node: once the lists converge at a node, they cannot diverge at a later node.
Therefore, checking for overlap amounts to finding the tail nodes for each list.

To find the first overlapping node, we first compute the length of each list. The first overlapping node is determined by advancing through
the longer list by the difference in lengths, and then advancing through the longer list by the difference in lengths, and then advancing
through both lists in tandem, stopping at the first common node. If we reach the end of a list without finding a common node, the lists do
not overlap. */

shared_ptr<ListNode<int>> OverlappingNoCycleLists (shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2) {
  int L1_len = Length(L1);
  int L2_len = Length(L2);

  // Advances the longer list to get equal length first
  AdvanceListByK(abs(L1_len - L2_len), L1_len > L2_len ? &L1 : &L2);
  while (L1 && L2 && L1 != L2) {
    L1 = L1->next;
    L2 = L2->next;
  }
  return L1; // nullptr implies there is no overlap between L1 and L2
}

int Length(shared_ptr<ListNode<int>> L) {
  int length = 0;
  while (L) {
    length++;
    L = L->next;
  }
  return length;
}

// Advances L by k steps
void AdvanceListByK(int k, shared_ptr<ListNode<int>>* L) {
  while (k--) {
    *L = (*L)->next;
  }
}

// O(n) time complexity and O(1) space complexity
