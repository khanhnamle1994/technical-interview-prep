/* In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.

Example:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX */

bool canTransform(string start, string end) {
  int len = end.size();
	int len2 = start.size();
	if(len != len2) return false;
	int count_r = 0;
	int count_l = 0;
	for(int i = 0; i < len; i++){
		if(start[i] == 'R') count_r++;
		else if(start[i] == 'L' && count_r) return false ;
		if(end[i] == 'R'){
			count_r--;
			if(count_r<0) return false;
		}
		if(start[len-i-1] == 'L') count_l++;
		else if(start[len-i-1] == 'R' && count_l) return false;
		if(end[len-i-1] == 'L'){
			count_l--;
			if(count_l<0) return false;
		}
	}
	if(count_r | count_l) return false;
	return true;
}
