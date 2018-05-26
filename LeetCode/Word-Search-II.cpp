// Given a 2D board and a list of words from the dictionary, find all words in the board.

// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

/* Example:

Input:
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

Output: ["eat","oath"] */

class TrieNode {
public:
  int is_word;
  vector<TrieNode*> next;
  TrieNode() {
      is_word = -1;
      next = vector<TrieNode*>(26, NULL);
  }
};

TrieNode* root;

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
  root = new TrieNode();
  buildTrie(words, root);
  //cout << root->next[0]->is_word;

  set<string> res;
  for(int i = 0; i < board.size(); i++){
      for(int j = 0; j < board[0].size(); j++){
          findWords(res, board, words, root, i, j);
      }
  }
  return vector<string>(res.begin(), res.end());
}

void buildTrie(vector<string>& words, TrieNode* root){
  TrieNode* curr;
  for(int i = 0; i < words.size(); i++){
      curr = root;
      for(char c: words[i]){
          if(!curr->next[c-'a']){
              curr->next[c-'a'] = new TrieNode();
          }
          curr = curr->next[c-'a'];
      }
      curr->is_word = i;
  }
  return;
}

void findWords(set<string>& res, vector<vector<char>>& board, vector<string>& words, TrieNode* node, int r, int c){
  if(board[r][c] == '.' || !node->next[board[r][c]-'a']) return;

  TrieNode* after = node->next[board[r][c]-'a'];
  if(after->is_word > -1) res.insert(words[after->is_word]);
  char letter = board[r][c];
  board[r][c] = '.';
  if(r-1 >= 0) findWords(res, board, words, after, r-1, c);
  if(r+1 < board.size()) findWords(res, board, words, after, r+1, c);
  if(c-1 >= 0) findWords(res, board, words, after, r, c-1);
  if(c+1 < board[0].size()) findWords(res, board, words, after, r, c+1);
  board[r][c] = letter;

  return;
}
