/* In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", and use the dial to spell a specific keyword in order to open the door.

Given a string ring, which represents the code engraved on the outer ring and another string key, which represents the keyword needs to be spelled. You need to find the minimum number of steps in order to spell all the characters in the keyword.

Initially, the first character of the ring is aligned at 12:00 direction. You need to spell all the characters in the string key one by one by rotating the ring clockwise or anticlockwise to make each character of the string key aligned at 12:00 direction and then by pressing the center button.

At the stage of rotating the ring to spell the key character key[i]:
1 - You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, where this character must equal to the character key[i].
2 - If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell, which also counts as 1 step. After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling. */

int helper(string &ring, int i, string &key, int j) {
    if (j == key.size()) return 0;
    if (dp[i][j] > 0) return dp[i][j];
    int k = i, r = 0, l = 0;
    while (ring[k] != key[j]) {
        k++;
        if (k == ring.size()) k = 0;
        r++;
    }
    r += helper(ring, k, key, j + 1) + 1;
    k = i;
    while (ring[k] != key[j]) {
        k--;
        if (k < 0) k = ring.size() - 1;
        l++;
    }
    l += helper(ring, k, key, j + 1) + 1;
    return dp[i][j] = min(r, l);
}

int dp[100][100] = {0};

int findRotateSteps(string ring, string key) {
  return helper(ring, 0, key, 0);
}
