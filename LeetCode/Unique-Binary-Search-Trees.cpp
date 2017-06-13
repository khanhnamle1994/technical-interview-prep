/* Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3 */

/* Analysis: DP works well in this problem.
For each sequence from 1 to n, # of BSTs equals: Sum of BSTs where each number (from 1 to n) is considered as the root node.
For each node, # of BSTs equals: # of bsts of its left child times # of bsts of its right child.

Denote bst[i] = the number of BSTs can be constructed that store values from 1..n.

   n = 1,  Node = {1},      bst[1]  = 1

   n = 2,  Node = {1, 2}
   when 1 is the root node, there is 1 bst
      1
       \
       2
   when 2 is the root node, there is 1 bst
      2
     /
   1
   bst[2] = 2

   n = 3,  Node = {1, 2, 3}
   when 1 is the root node, bst[3] =  bst[3] + bst[2] where stores 2 values (2 and 3)
   1                                                   1                   1
    \                                 =                 \                    \
    BSTs of {2,3}                              2                    3
                                                          \                   /
                                                           3                2
   when 2 is the root node, bst[3] =  bst[3] + bst[1] + bst[1]
             2
            /  \
           1   3
   when 3 is the root node, bst[3] =  bst[3] + bst[2] where stores 2 values (1 and 2)
                      3                                 3                   3
                   /                 =                 /                    /
    BSTs of {1,2}                            2                   1
                                                      /                       \
                                                    1                         2
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> table(n + 1,0);
        if (n == 0){
          return 0;
        }
        table[0] = 1;
        table[1] = 1;
        table[2] = 2;
        for (int i = 3; i <= n; i++){
            int res=0;
            for (int j = 0; j <= i - 1; j++){
                res = res + table[j] * table[i - 1 - j];
            }
            table[i] = res;
        }
        return table[n];
    }
};
