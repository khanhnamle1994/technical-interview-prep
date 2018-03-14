// You're working with an intern that keeps coming to you with JavaScript code that won't run because the braces, brackets, and parentheses are off. To save you both some time, you decide to write a braces/brackets/parentheses validator.

// Let's say:
// * '(', '{', '[' are called "openers."
// * ')', '}', ']' are called "closers."

// Write an efficient function that tells us whether or not an input string's openers and closers are properly nested.

// Examples:
// * "{ [ ] ( ) }" should return true
// * "{ [ ( ] ) }" should return false
// * "{ [ }" should return false

/* Solution
We iterate through our string, making sure that:
1 - each closer corresponds to the most recently seen, unclosed opener
2 - every opener and closer is in a pair

We use a stack ↴ to keep track of the most recently seen, unclosed opener. And if the stack is ever empty when we come to a closer, we know that closer doesn't have an opener.

So as we iterate:
* If we see an opener, we push it onto the stack.
* If we see a closer, we check to see if it is the closer for the opener at the top of the stack. If it is, we pop from the stack. If it isn't, or if the stack is empty, we return false.

If we finish iterating and our stack is empty, we know every opener was properly closed. */

bool isValid(const string& code)
{
    unordered_map<char, char> openersToClosers {
        make_pair('(', ')'),
        make_pair('[', ']'),
        make_pair('{', '}')
    };

    unordered_set<char> closers {
        ')', ']', '}'
    };

    stack<char> openersStack;

    for (char c : code) {
        if (openersToClosers.find(c) != openersToClosers.end()) {
            openersStack.push(c);
        }
        else if (closers.find(c) != closers.end()) {
            if (openersStack.empty()) {
                return false;
            }
            else {
                char lastUnclosedOpener = openersStack.top();
                openersStack.pop();

                // if this closer doesn't correspond to the most recently
                // seen unclosed opener, short-circuit, returning false
                if (openersToClosers[lastUnclosedOpener] != c) {
                    return false;
                }
            }
        }
    }

    return openersStack.empty();
}

// Complexity
// O(n) time (one iteration through the string), and O(n) space (in the worst case, all of our characters are openers, so we push them all onto the stack).
