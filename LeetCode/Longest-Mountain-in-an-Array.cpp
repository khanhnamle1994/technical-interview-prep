/* Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:
>> B.length >= 3
>> There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]

(Note that B could be any subarray of A, including the entire array A.)

Given an array A of integers, return the length of the longest mountain.

Return 0 if there is no mountain.

Example 1:
Input: [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

Example 2:
Input: [2,2,2]
Output: 0
Explanation: There is no mountain.

int longestMountain(vector<int>& A) {
    int n=A.size(),len=0, maxlen=0;
    if(n<3) return 0;
    for(int i=1;i<n-1;i++)
    {
        if(A[i]>A[i-1]&&A[i]>A[i+1])
        {
            len=1;//Now A[i] is the peak.
            int left=i-1, right=i+1;
            while(left>=0&&A[left]<A[left+1]){len++;left--;}
            while(right<n&&A[right-1]>A[right]){len++;right++;}
            maxlen=max(len,maxlen);
        }
    }
    return maxlen;
}
