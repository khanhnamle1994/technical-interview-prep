// I figured out how to get rich: online poker.

// I suspect the online poker game I'm playing shuffles cards by doing a single riffle. ↴

// To prove this, let's write a function to tell us if a full deck of cards shuffledDeck is a single riffle of two other halves half1 and half2.

// We'll represent a stack of cards as a vector of integers in the range 1..521..52 (since there are 5252 distinct cards in a deck).
// Why do I care? A single riffle is not a completely random shuffle. If I'm right, I can make more informed bets and get rich and finally prove to my ex that I am not a "loser with an unhealthy cake obsession" (even though it's too late now because she let me go and she's never getting me back).

// Solution
// We walk through shuffledDeck, seeing if each card so far could have come from a riffle of the other two halves. To check this, we:

/*
1. Keep pointers to the current index in half1, half2, and shuffledDeck.
2. Walk through shuffledDeck from beginning to end.
3. If the current card in shuffledDeck is the same as the top card from half1, increment half1Index and keep going. This can be thought of as "throwing out" the top cards of half1 and shuffledDeck, reducing the problem to the remaining cards in the stacks.
4. Same as above with half2.
5. If the current card isn't the same as the card at the top of half1 or half2, we know we don't have a single riffle.
6. If we make it all the way to the end of shuffledDeck and each card checks out, we know we do have a single riffle. */

bool isSingleRiffle(
    const vector<int>& half1,
    const vector<int>& half2,
    const vector<int>& shuffledDeck)
{
    size_t half1Index = 0;
    size_t half2Index = 0;
    size_t half1MaxIndex = half1.size() - 1;
    size_t half2MaxIndex = half2.size() - 1;

    for (int card : shuffledDeck) {

        // if we still have cards in half1
        // and the "top" card in half1 is the same
        // as the top card in shuffledDeck
        if (half1Index <= half1MaxIndex && card == half1[half1Index]) {
            ++half1Index;
        }

        // if we still have cards in half2
        // and the "top" card in half2 is the same
        // as the top card in shuffledDeck
        else if (half2Index <= half2MaxIndex && card == half2[half2Index]) {
            ++half2Index;
        }

        // if the top card in shuffledDeck doesn't match the top
        // card in half1 or half2, this isn't a single riffle.
        else {
            return false;
        }
    }

    // all cards in shuffledDeck have been "accounted for"
    // so this is a single riffle!
    return true;
}

// Complexity
// O(n) time and O(1) additional space.
