// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

/* Example:
Input: [2,1,5,6,2,3]
Output: 10 */

int largestRectangleArea(vector<int>& heights) {
  stack<int> S;
  heights.push_back(0);
  int res = 0;

  for(int i = 0; i<heights.size(); i++)
  {
      if(S.empty() || heights[i] > heights[S.top()])
          S.push(i);
      else
      {
          int temp = S.top();
          S.pop();
          int dist = S.empty() ? i : i-S.top() -1;
          res = max(res, dist * heights[temp]);
          i--; // set i one step back.  to make sure the bar i will be processed.
      }
  }

  return res;
}

/* Solution:
For every bar ‘x’, we calculate the area with ‘x’ as the smallest bar in the rectangle. If we calculate such area for every bar ‘x’ and find the maximum of all areas, our task is done. How to calculate area with ‘x’ as smallest bar? We need to know index of the first smaller (smaller than ‘x’) bar on left of ‘x’ and index of first smaller bar on right of ‘x’. Let us call these indexes as ‘left index’ and ‘right index’ respectively. We traverse all bars from left to right, maintain a stack of bars. Every bar is pushed to stack once. A bar is popped from stack when a bar of smaller height is seen. When a bar is popped, we calculate the area with the popped bar as smallest bar. How do we get left and right indexes of the popped bar – the current index tells us the ‘right index’ and index of previous item in stack is the ‘left index’.

Following is the complete algorithm.
1 - Create an empty stack.
2 - Push 0 to end of the given bar array. Because bar with height= 0 means lower than any other bars. This ensure everything in static will be popped out for calculation.
3 - Loop from right to left,
>> If stack is empty or bar[i] is higher than bar at top of stack, push index i into stack.
>> If bar[i] is lower than the top of stack, pop out the top of stack, say it is hist[tp]. Use it as lowest bar. the leftIndex is current top of stack. the rightIndex is i.
4 - If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar. until seeing a bar in stack lower than current bar[i] */
