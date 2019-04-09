/* Some people will make friend requests. The list of their ages is given and ages[i] is the age of the ith person.

Person A will NOT friend request person B (B != A) if any of the following conditions are true:
>> age[B] <= 0.5 * age[A] + 7
>> age[B] > age[A]
>> age[B] > 100 && age[A] < 100

Otherwise, A will friend request B.

Note that if A requests B, B does not necessarily request A.  Also, people will not friend request themselves.

How many total friend requests are made?

Example 1:
Input: [16,16]
Output: 2
Explanation: 2 people friend request each other.

Example 2:
Input: [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.

Example 3:
Input: [20,30,100,110,120]
Output:
Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100. */

bool request(int a, int b) {
    return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
}

int numFriendRequests(vector<int>& ages) {
    unordered_map<int,int> count;
    for (int &age: ages) count[age]++;
    int res = 0;
    for (auto &a: count) for (auto &b: count)
        if (request(a.first, b.first)) res += a.second * (b.second - (a.first == b.first ? 1 : 0));
    return res;
}
