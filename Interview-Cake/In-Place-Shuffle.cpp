// Write a function for doing an in-place ↴ shuffle of a vector.

// The shuffle must be "uniform," meaning each item in the original vector must have the same probability of ending up in each spot in the final vector.

// Assume that you have a function getRandom(floor, ceiling) for getting a random integer that is >= floor and <= ceiling.

// Solution
// We choose a random item to move to the first index, then we choose a random other item to move to the second index, etc. We "place" an item in an
// index by swapping it with the item currently at that index.

// Crucially, once an item is placed at an index it can't be moved. So for the first index we choose from nn items, for the second index we choose
// from n-1n−1 items, etc.

size_t getRandom(size_t floor, size_t ceiling);

void shuffle(vector<int>& theVector)
{
    // if it's 1 or 0 items, just return
    if (theVector.size() <= 1) {
        return;
    }

    // walk through from beginning to end
    for (size_t indexWeAreChoosingFor = 0;
            indexWeAreChoosingFor < theVector.size() - 1;
            ++indexWeAreChoosingFor) {

        // choose a random not-yet-placed item to place there
        // (could also be the item currently in that spot)
        // must be an item AFTER the current item, because the stuff
        // before has all already been placed
        size_t randomChoiceIndex = getRandom(indexWeAreChoosingFor,
                theVector.size() - 1);

        // place our random choice in the spot by swapping
        if (randomChoiceIndex != indexWeAreChoosingFor) {
            swap(theVector[indexWeAreChoosingFor], theVector[randomChoiceIndex]);
        }
    }
}

// This is a semi-famous algorithm known as the Fisher-Yates shuffle (sometimes called the Knuth shuffle).

// Complexity
// O(n) time and O(1) space.
