// Given integers n and k, find the lexicographically k-th smallest integer in the range from 1 to n.

/* Example:

Input:
n: 13   k: 2

Output:
10

Explanation:
The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10. */

int solve(int n, int k, int prevdigs, int len) /// prevdigs are all digits known so far.
{
    if (k == 0)          /// in this function, k = 0 means the 1st number.
        return prevdigs; /// e.g. 3XX's 0th string is 3; just the prevdigs;
    k --;                /// take account of the "3XX's 0th" case. minus one here to make the code below cleaner.
    if (len == 1)        /// the ending condition of recursion. For 1 digit number, just get k;
        return prevdigs*10 + k;
    /// suppose n = 345 in all comments below;
    int whole = pow(10, len - 1); /// 100
    int sigdig = n / whole;       /// 3
    int remain = n % whole;       /// 45
    int allones_1 = (whole - 1) / 9;  /// 11
    int allones_0 = allones_1*10 + 1; /// 111
    int allones_2 = allones_1 / 10;   /// 1
    int low_bar =  allones_0 * sigdig; /// 111 * 3 = 333 The number of strs before 3 (containing 111 digits starting with 0)
    int high_bar = low_bar + allones_1 + remain + 1; /// 333 + 11 + 45 + 1 (11 is 3, 30, 31 ... 39)
    if (k < low_bar)   /// k is before 3
    {
        int curdig = k / allones_0; /// figure out the current digit is 0, 1 or 2;
        return solve(allones_1 * 9, k % allones_0, prevdigs*10 + curdig, len - 1); /// allones_1 * 9 makes 99, meaning search everything
    }                                                                              /// with length len-1
    if (k >= high_bar) /// k is after 39 (largest in 3XX)
    {
        k -= high_bar;
        int curdig = sigdig + k / allones_1 + 1; /// figure out the current digit among 4~9;
        return solve(allones_2 * 9, k % allones_1, prevdigs * 10 + curdig, len - 2); ///allones_2 * 9 makes 9, meaning search everything
    }                                                                                ///with length len-2
    k -= low_bar;
    int curdig = sigdig;
    return solve(remain, k, prevdigs * 10 + curdig, len - 1); /// search in 45 with length 2;
}

int findKthNumber(int n, int k)
{
    int len = 0; /// length of n
    for(int m = n; m > 0; m/= 10, ++len);
    k += (pow(10, len) - 1)/9; /// solve function considers 0's before 1; we make up this difference first;
    return solve(n, k, 0, len); ///len is important, o/w when k = 5 in a middle round, you don't know it's X005 or X05,
}


/// O(log10(N)) Time & Space
/// The main idea to simplify the implementation is, when count, start with empty then 0's at a certain length;
/// E.g. when do n = 345, k = 250, instead of counting from 1, 10, 100, ...., count from EMPTY, 0, 00, 000, 001, 002..09, 091, 092, ..099, 1
/// Therefore, I count 112 (there is an EMPTY at first) more than you should. So I add this difference first;
/// The reason why I do it this way is it will greatly simplify the implementation later.
/// Suppose I'm in an intermediate round, I have prevdigs = 3. I want to calculate solve(45, 27) now,
/// because there is a leading digit, it makes 0, 00 or even EMPTY valid now -- they can make 30, 300, 3 respectively.
/// So in all intermediate rounds, it's beneficial to consider 0, 00, EMPTY before 1XX. The only exceptional round is the first one.
/// So I just need to do some manipulate with the first round, then we are all good.
