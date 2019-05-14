/* Given two integers A and B, return any string S such that:

>> S has length A + B and contains exactly A 'a' letters, and exactly B 'b' letters;
>> The substring 'aaa' does not occur in S;
>> The substring 'bbb' does not occur in S.

Example 1:
Input: A = 1, B = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.

Example 2:
Input: A = 4, B = 1
Output: "aabaa" */

string strWithout3a3b(int A, int B) {
    string t;
    char a = 'a', b = 'b';
    if(B > A) {
        swap(A, B);
        swap(a, b);
    }
    while(A || B) {
        if(A) {
            t += a;
            --A;
            if(A >= 1) {
                t += a;
                --A;
            }
        }
        if(B) {
            t += b;
            --B;
            if(B >= 1 && A - B < 2) {
                t += b;
                --B;
            }
        }
    }
    return t;
}
