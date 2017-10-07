// We are playing the Guess Game. The game is as follows:

// I pick a number from 1 to n. You have to guess which number I picked.

// Every time you guess wrong, I'll tell you whether the number is higher or lower.

// You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

// -1 : My number is lower
// 1 : My number is higher
// 0 : Congrats! You got it!

// Example: n = 10, I pick 6. Return 6.

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

int guessNumber(int n) {
    int maxNumber = n, minNumber = 1;
    while (true) {
        int meanNumber = (maxNumber - minNumber) / 2 + minNumber;
        // Do NOT use (maxNumber+minNumber)/2 in case of over flow
        int res = guess(meanNumber);
        if (res == 0) {
            return meanNumber;
        } else if (res == 1) {
            minNumber = meanNumber + 1;
        } else {
            maxNumber = meanNumber - 1;
        }
    }
}
