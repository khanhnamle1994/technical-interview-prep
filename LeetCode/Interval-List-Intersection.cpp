/* Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

Example:
Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists. */

vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
  vector<Interval> ret;
	for(int i=0,j=0;i<A.size()&&j<B.size();A[i].end<B[j].end?i++:j++)
		if(!(A[i].start>B[j].end || B[j].start>A[i].end))
			ret.push_back(Interval(max(A[i].start,B[j].start),min(A[i].end,B[j].end)));
	return ret;
}
