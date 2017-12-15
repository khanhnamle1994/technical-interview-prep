// Follow up for problem "Populating Next Right Pointers in Each Node".
// What if the given tree could be any binary tree? Would your previous solution still work?

/* For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL */

/**
  * Definition for binary tree with next pointer.
  * struct TreeLinkNode {
  *  int val;
  *  TreeLinkNode *left, *right, *next;
  *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  * };
  */

void connect(TreeLinkNode *root) {
  TreeLinkNode *now, *tail, *head;

  now = root;
  head = tail = NULL;
  while(now)
  {
      if (now->left)
          if (tail) tail = tail->next =now->left;
          else head = tail = now->left;
      if (now->right)
          if (tail) tail = tail->next =now->right;
          else head = tail = now->right;
      if(!(now = now->next))
      {
          now = head;
          head = tail=NULL;
      }
  }
}
