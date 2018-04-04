/* You're working on a secret team solving coded transmissions.

Your team is scrambling to decipher a recent message, worried it's a plot to break into a major European National Cake Vault. The message has been mostly deciphered, but all the words are backwards! Your colleagues have handed off the last step to you.

Write a function reverseWords() that takes a message as a string and reverses the order of the words in-place.

For example:

string message = "cake pound steal";
reverseWords(message);
cout << message << endl;
// prints: "steal pound cake"

When writing your function, assume the message contains only letters and spaces, and all words are separated by one space. */

/* Solution
We'll write a helper function reverseCharacters() that reverses all the characters between a leftIndex and rightIndex. We use it to:
1 - Reverse all the characters in the entire message, giving us the correct word order but with each word backwards.
2 - Reverse the characters in each individual word. */

void reverseCharacters(string& str, size_t leftIndex, size_t rightIndex)
{
    // walk towards the middle, from both sides
    while (leftIndex < rightIndex) {

        // swap the left char and right char
        swap(str[leftIndex], str[rightIndex]);
        ++leftIndex;
        --rightIndex;
    }
}

void reverseWords(string& message)
{
    // first we reverse all the characters in the entire message
    reverseCharacters(message, 0, message.length() - 1);
    // this gives us the right word order
    // but with each word backwards

    // now we'll make the words forward again
    // by reversing each word's characters

    // we hold the index of the *start* of the current word
    // as we look for the *end* of the current word
    size_t currentWordStartIndex = 0;
    for (size_t i = 0; i <= message.length(); ++i) {

        // found the end of the current word!
        if (i == message.length() || message[i] == ' ') {

            // if we haven't exhausted the string our
            // next word's start is one character ahead
            reverseCharacters(message, currentWordStartIndex, i - 1);
            currentWordStartIndex = i + 1;
        }
    }
}

// Complexity
// O(n) time and O(1) space!
