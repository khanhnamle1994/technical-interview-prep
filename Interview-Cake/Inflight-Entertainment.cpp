// You've built an inflight entertainment system with on-demand movie streaming.

// Users on longer flights like to start a second movie right when their first one ends, but they complain that the plane usually lands
// before they can see the ending. So you're building a feature for choosing two movies whose total runtimes will equal the exact flight
// length.

// Write a function that takes an integer flightLength (in minutes) and a vector of integers movieLengths (in minutes) and returns a
// boolean indicating whether there are two numbers in movieLengths whose sum equals flightLength.

// Solution
// We make one pass through movieLengths, treating each item as the firstMovieLength. At each iteration, we:

// 1 - See if there's a matchingSecondMovieLength we've seen already (stored in our movieLengthsSeen unordered set) that is equal to
// flightLength - firstMovieLength. If there is, we short-circuit and return true.
// 2 - Keep our movieLengthsSeen unordered set up to date by throwing in the current firstMovieLength.

// We know users won't watch the same movie twice because we check movieLengthsSeen for matchingSecondMovieLength before we've put
// firstMovieLength in it!

bool canTwoMoviesFillFlight(const vector<int>& movieLengths, int flightLength)
{
    // movie lengths we've seen so far
    unordered_set<int> movieLengthsSeen;

    for (int firstMovieLength : movieLengths) {

        int matchingSecondMovieLength = flightLength - firstMovieLength;
        if (movieLengthsSeen.find(matchingSecondMovieLength) != movieLengthsSeen.end()) {
            return true;
        }

        movieLengthsSeen.insert(firstMovieLength);
    }

    // we never found a match, so return false
    return false;
}

// Complexity
// O(n) time, and O(n) space. Note while optimizing runtime we added a bit of space cost.
