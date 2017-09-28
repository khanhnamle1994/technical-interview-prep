// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

/* Analysis:

This problem can be solved using the  Boyer-Moore majority vote algorithm.

Before we are digging into this algorithm, let's see one basic observation:

How many majority elements at most in this problem?
Answer: Two.
Explanation: At most there are 3 elements appear exactly n/3 times. So for more than n/3 times, at most there are 2 elements.

Now we discuss the Moore majority vote algorithm. Quoted from wiki:
" The algorithm is carried out in two steps:
1. Eliminate all elements except one.
Iterating through the array of numbers, maintain a current candidate and a counter initialized to 0. With the current element x in iteration, update the
counter and (possibly) the candidate:
+ If the counter is 0, set the current candidate to x and the counter to 1.
+ If the counter is not 0, increment or decrement the counter based on whether x is the current candidate.

2. Determine if the remaining element is a valid majority element.
With the candidate acquired in step 1, iterate through the array of numbers and count its occurrences. Determine if the result is more than half of the
sequence's length. If so, the candidate is the majority. Otherwise, the sequence doesn't contain a majority. "

The key idea of this algorithm is "decrement" of the counter when new elements are different from all the current candidates.  This "decrement" operation
is to cancel out the elements that do not appear most times in the array. Therefore, after one scan, the candidates are the elements which appear most of
the times. The last step is to check if these candidates are satisfied with the condition of more than n/3 times. */

vector<int> majorityElement(vector<int>& nums) {
    int cnt1 = 0, cnt2 = 0, a = 0, b = 1;

    for(auto n : nums) {
        if (a == n){
            cnt1++;
        }
        else if (b == n) {
            cnt2++;
        }
        else if (cnt1 == 0) {
            a = n;
            cnt1 = 1;
        }
        else if (cnt2 == 0) {
            b = n;
            cnt2 = 1;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = cnt2 = 0;
    for(auto n : nums){
        if (n == a)   cnt1++;
        else if (n == b)  cnt2++;
    }

    vector<int> res;
    if (cnt1 > nums.size()/3)   res.push_back(a);
    if (cnt2 > nums.size()/3)   res.push_back(b);
    return res;
}
