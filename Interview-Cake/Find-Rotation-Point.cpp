/* I want to learn some big words so people think I'm smart.

I opened up a dictionary to a page in the middle and started flipping through, looking for words I didn't know. I put each word
I didn't know at increasing indices in a huge vector I created in memory. When I reached the end of the dictionary, I started from
the beginning and did the same thing until I reached the page I started at.

Now I have a vector of words that are mostly alphabetical, except they start somewhere in the middle of the alphabet, reach the end,
and then start from the beginning of the alphabet. In other words, this is an alphabetically ordered vector that has been "rotated."
For example:

  const vector<string> words {
    "ptolemaic",
    "retrograde",
    "supplant",
    "undulate",
    "xenoepist",
    "asymptote",  // <-- rotates here!
    "babka",
    "banoffee",
    "engender",
    "karpatka",
    "othellolagkage",
};

Write a function for finding the index of the "rotation point," which is where I started working from the beginning of the dictionary.
This vector is huge (there are lots of words I don't know) so we want to be efficient here. */

/* Solution
This is a modified version of binary search. At each iteration, we go right if the item we're looking at is greater than the first
item and we go left if the item we're looking at is less than the first item.

We keep track of the lower and upper bounds on the rotation point, calling them floorIndex and ceilingIndex (initially we called them
"floor" and "ceiling," but because we didn't imply the type in the name we got confused and created bugs). When floorIndex and
ceilingIndex are directly next to each other, we know the floor is the last item we added before starting from the beginning of the
dictionary, and the ceiling is the first item we added after. */

size_t findRotationPoint(const vector<string>& words)
{
  size_t floorIndex = 0;
  size_t ceilingIndex = words.size() - 1;

  while (floorIndex < ceilingIndex) {

      // guess a point halfway between floor and ceiling
      size_t guessIndex = floorIndex + ((ceilingIndex - floorIndex) / 2);

      // if guess comes after first word or is the first word
      if (words[guessIndex] >= words[0]) {
          // go right
          floorIndex = guessIndex;
      }
      else {
          // go left
          ceilingIndex = guessIndex;
      }

      // if floor and ceiling have converged
      if (floorIndex + 1 == ceilingIndex) {

          // between floor and ceiling is where we flipped to the beginning
          // so ceiling is alphabetically first
          break;
      }
  }

  return ceilingIndex;
}

/* Complexity
Each time we go through the while loop, we cut our range of indices in half, just like binary search. So we have O(lgn) loop iterations.

In each loop iteration, we do some arithmetic and a string comparison. The arithmetic is constant time, but the string comparison requires
looking at characters in both words—every character in the worst case. Here, we'll assume our word lengths are bounded by some constant
so we'll say the string comparison takes constant time.

Putting everything together, we do O(lgn) iterations, and each iteration is O(1) time. So our time complexity is O(lgn).

We use O(1) space to store the first word and the floor and ceiling indices. */
