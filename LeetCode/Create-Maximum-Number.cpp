// Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits.

/* Example 1:

Input:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5

Output:
[9, 8, 6, 5, 3]

Example 2:

Input:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5

Output:
[6, 7, 6, 0, 4]

Example 3:

Input:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3

Output:
[9, 8, 9] */

#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)

// create max number of length t from single non-empty vector
void getMax(int* num, int& len, int* result, int& t, int& sortedLen)
{
	int n, top = 0;
	result[0] = num[0];
	const int need2drop = len - t;
	for (int i = 1; i < len; ++i){
		n = num[i];
		while (top >= 0 && result[top] < n && (i - top) <= need2drop) --top; // i - top means already dropped i - top numbers
		if (i - top > need2drop){
			sortedLen = MAX(1,top);
			while (++top < t) result[top] = num[i++];
			return;
		}
		if (++top < t) result[top] = n;
		else top = t - 1;
	}
}

// create max number of different length from single vector
void dp(int *num, int len, int&sortedLen, int& minL, int& maxL, int *res, int &k){
	int  j, *head, *prevhead = res;
	const int soi = sizeof(int);
	getMax(num, len, res, maxL,sortedLen);
	for (int l = maxL; l > MAX(minL,1); --l){
		head = prevhead + k;
		memcpy(head, prevhead, l*soi);
		for (j = sortedLen; j < l; ++j){
			if (head[j] > head[j - 1]){
				sortedLen = MAX(1, j - 1);
				memcpy(head + j - 1, prevhead + j, soi*(l - j));
				break;
			}
		}
		if (j == l) sortedLen = l;
		prevhead = head;
	}
}

// merge max number created from single vector
void merge(int* num1,int len1,int* num2,int len2,int* result,int& resSize){
	int i = 0, j = 0, k = 0;
	while (i < resSize){
		if (j < len1 && k < len2){
			if (num1[j] > num2[k])
				result[i++] = num1[j++];
			else if (num1[j] < num2[k])
				result[i++] = num2[k++];
			else{
				int remaining1 = len1 - j, remaining2 = len2 - k, tmp = num1[j];
				int flag = memcmp(num1 + j, num2 + k, sizeof(int) * MIN(remaining1, remaining2));
				flag = (flag == 0 ? (remaining1>remaining2 ? 1 : -1) : flag);
				int * num = flag > 0 ? num1 : num2;
				int & cnt = flag > 0 ? j : k;
				int len = flag > 0 ? len1 : len2;
				while (num[cnt]==tmp && cnt < len && i<resSize) result[i++] = num[cnt++];
			}
		}
		else if (j < len1) result[i++] = num1[j++];
		else result[i++] = num2[k++];
	}
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int soi = sizeof(int), len1 = nums1.size(), len2 = nums2.size(), step = k*soi;
  	int minL1 = MAX(0, k - len2), maxL1 = MIN(k, len1), minL2 = k - maxL1, maxL2 = k - minL1, range = maxL1 - minL1 + 1;
  	int * res = new int[range * k * 2 + 2 * k], *dp1 = res + k, *dp2 = res + range*k+k, *tmp=res+range*2*k+k;
  	memset(res, 0, step);
  	int sortedLen1 = 1, sortedLen2 = 1;
  	if (len1 == 0 && len2 > 0) getMax(&nums2[0], len2, res, k, sortedLen2);
  	else if (len1 > 0 && len2 == 0) getMax(&nums1[0], len1, res, k, sortedLen2);
  	else if (len1 > 0 && len2 > 0){
  		dp(&nums1[0], len1, sortedLen1, minL1, maxL1, dp1,k);
  		dp(&nums2[0], len2, sortedLen2, minL2, maxL2, dp2,k);
  		if (sortedLen1 + sortedLen2 > k){
  			merge(dp1 + k*(maxL1 - sortedLen1), sortedLen1, dp2 + k*(maxL2 - sortedLen2), sortedLen2, tmp, k);
  			vector<int> resv(tmp, tmp + k);
  			delete[] res;
  			return resv;
  		}
  		for (int i = minL1; i <= maxL1; ++i){
  			merge(dp1+k*(maxL1-i), i, dp2+k*(maxL2-k+i), (k-i), tmp,k);
  			if (memcmp(res, tmp, step) < 0) memcpy(res, tmp, step);
  		}
  	}
  	vector<int> resv(res, res + k);
  	delete[] res;
  	return resv;
}

// The basic idea:

// To create max number of length k from two arrays, you need to create max number of length i from array one and max number of length k-i from array two, then combine them together. After trying all possible i, you will get the max number created from two arrays.

// Optimization:

/* 1 - Suppose nums1 = [3, 4, 6, 5], nums2 = [9, 1, 2, 5, 8, 3], the maximum number you can create from nums1 is [6, 5] with length 2. For nums2, it's [9, 8, 3] with length 3. Merging the two sequence, we have [9, 8, 6, 5, 3], which is the max number we can create from two arrays without length constraint. If the required length k<=5, we can simply trim the result to required length from front. For instance, if k=3, then [9, 8, 6] is the result.

2 - Suppose we need to create max number with length 2 from num = [4, 5, 3, 2, 1, 6, 0, 8]. The simple way is to use a stack, first we push 4 and have stack [4], then comes 5 > 4, we pop 4 and push 5, stack becomes [5], 3 < 5, we push 3, stack becomes [5, 3]. Now we have the required length 2, but we need to keep going through the array in case a larger number comes, 2 < 3, we discard it instead of pushing it because the stack already grows to required size 2. 1 < 3, we discard it. 6 > 3, we pop 3, since 6 > 5 and there are still elements left, we can continue to pop 5 and push 6, the stack becomes [6], since 0 < 6, we push 0, the stack becomes [6, 0], the stack grows to required length again. Since 8 > 0, we pop 0, although 8 > 6, we can't continue to pop 6 since there is only one number, which is 8, left, if we pop 6 and push 8, we can't get to length 2, so we push 8 directly, the stack becomes [6, 8].

3 - In the basic idea, we mentioned trying all possible length i. If we create max number for different i from scratch each time, that would be a waste of time. Suppose num = [4, 9, 3, 2, 1, 8, 7, 6], we need to create max number with length from 1 to 8. For i==8, result is the original array. For i==7, we need to drop 1 number from array, since 9 > 4, we drop 4, the result is [9, 3, 2, 1, 8, 7, 6]. For i==6, we need to drop 1 more number, 3 < 9, skip, 2 < 3, skip, 1 < 2, skip, 8 > 1, we drop 1, the result is [9, 3, 2, 8, 7, 6]. For i==5, we need to drop 1 more, but this time, we needn't check from beginning, during last scan, we already know [9, 3, 2] is monotonically non-increasing, so we check 8 directly, since 8 > 2, we drop 2, the result is [9, 3, 8, 7, 6]. For i==4, we start with 8, 8 > 3, we drop 3, the result is [9, 8, 7, 6]. For i==3, we start with 8, 8 < 9, skip, 7 < 8, skip, 6 < 7, skip, by now, we've got maximum number we can create from num without length constraint. So from now on, we can drop a number from the end each time. The result is [9, 8, 7], For i==2, we drop last number 7 and have [9, 8]. For i==1, we drop last number 8 and have [9]. */
