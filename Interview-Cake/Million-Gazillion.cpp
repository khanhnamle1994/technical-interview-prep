/* I wrote a crawler that visits web pages, stores a few keywords in a database, and follows links to other web pages. I noticed that my
crawler was wasting a lot of time visiting the same pages over and over, so I made a unordered set, visited, where I'm storing URLs I've
already visited. Now the crawler only visits a URL if it hasn't already been visited.

Thing is, the crawler is running on my old desktop computer in my parents' basement (where I totally don't live anymore), and it keeps
running out of memory because visited is getting so huge.

How can I trim down the amount of space taken up by visited? */

// Solution

/* We can use a trie. If you've never heard of a trie, think of it this way:

Let's make visited a nested unordered map where each map has keys of just one character. So we would store 'google.com' as
visited['g']['o']['o']['g']['l']['e']['.']['c']['o']['m']['*'] = true.

The '*' at the end means 'this is the end of an entry'. Otherwise we wouldn't know what parts of visited are real URLs and which parts are
just prefixes. In the example above, 'google.co' is a prefix that we might think is a visited URL if we didn't have some way to mark 'this
is the end of an entry.'

Now when we go to add 'google.com/maps' to visited, we only have to add the characters '/maps', because the 'google.com' prefix is already
there. Same with 'google.com/about/jobs'.

We can visualize this as a tree, where each character in a string corresponds to a node. To check if a string is in the trie, we just
descend from the root of the tree to a leaf, checking for a node in the tree for each character of in string.

How could we implement this structure? There are lots of ways! We could use nested unordered maps, nodes and pointers, or some combination
of the two. Evaluating the pros and cons of different options and choosing one is a great thing to do in a programming interview.

In our implementation, we chose to use nested unordered maps. To determine if a given site has been visited, we just call
checkPresentAndAdd(), which checks if a given string is present in the trie and adds it to the trie if it's not. */

class TrieNode
{
private:

  unordered_map<char, TrieNode*> nodeChildren_;

public:
  TrieNode() :
      nodeChildren_()
  {}

  ~TrieNode()
  {
      for (auto& v : nodeChildren_) {
          delete v.second;
      }
  }

  // copy and move constructors and assignment operators not shown

  bool hasChildNode(char ch) const
  {
      return nodeChildren_.find(ch) != nodeChildren_.cend();
  }

  void makeChildNode(char ch)
  {
      nodeChildren_.insert(make_pair(ch, new TrieNode()));
  }

  TrieNode * getChildNode(char ch)
  {
      auto it = nodeChildren_.find(ch);
      if (it == nodeChildren_.cend()) {
          return nullptr;
      }
      else {
          return it->second;
      }
  }
};

class Trie
{
private:
  TrieNode* rootNode_;
  static constexpr char END_OF_WORD_MARKER = '\0';

public:
  Trie() :
      rootNode_(new TrieNode())
  {
  }

  ~Trie()
  {
      delete rootNode_;
  }

  // copy and move constructors and assignment operators not shown

  bool checkPresentAndAdd(const string& word)
  {
      TrieNode* currentNode = rootNode_;
      bool isNewWord = false;

      // Work downwards through the trie, adding nodes
      // as needed, and keeping track of whether we add
      // any nodes.
      for (const char ch : word) {
          if (!currentNode->hasChildNode(ch)) {
              isNewWord = true;
              currentNode->makeChildNode(ch);
          }
          currentNode = currentNode->getChildNode(ch);
      }

      // Explicitly mark the end of a word.
      // Otherwise, we might say a word is
      // present if it is a prefix of a different,
      // longer word that was added earlier.
      if (!currentNode->hasChildNode(END_OF_WORD_MARKER)) {
          isNewWord = true;
          currentNode->makeChildNode(END_OF_WORD_MARKER);
      }

      return isNewWord;
  }
};
