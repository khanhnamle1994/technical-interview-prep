// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.

/* Example:
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index. */

int jump(vector<int>& nums) {
  int maxlen = nums.size() - 1;//the max steps we need, because we already in the first position,so minus one.
  int start = 0;//current positon
  int offset = 0;//from which position we may stop before current position step lenght exhausted.,
	//befor we get to current position, some index already check, we don't repeat it.
  int step = 0;//total steps

  while(true)
  {
      if(maxlen == 0 && start == 0)//don't need to jump
      {
          break;
      }

      if(maxlen <= nums[start])//just need one more jump
      {
          ++step;
          break;
      }

      int nstart = start + nums[start];
      int sublen = nums[start] + nums[nstart];//LENGTH as initial value
      int mnstart = nstart;

      for(int i = offset; i < mnstart; ++i)//find the max LENGTH_x
      {
          if(i - start + nums[i] > sublen)
          {
              nstart = i;
              sublen = i - start + nums[i];
          }
      }

      maxlen -= (nstart - start);
      offset = mnstart + 1;//recode next time from where start to check
      start = nstart;
      ++step;
  }

  return step;
}

/* For some position.
cast 1: We can exhaust it's step length, call this type of jump "J1"
cast 2: We can stop prematurely, call this type of jump "J2"
if we chose case 2, we prematurely get one more jump time, Does this really we want ? if the new position has long enough step,this just we want!.

Has current position's index be "I", step lenght be "L",
case 1: total step length of this "J1" jump and next "J1" jump is L + nums[i + L], call this length as "LENGTH".
case 2: For each index "i" in (I, I+L) , total step length of this "J1" jump and next "J2" jump is (i - I) + nums[i], call these length "LENGTH_1 LENGTH_2 .......LENGTH_X"

the max value of LENGTH, LENGTH_1, LENGTH_2 ... LENGTH_X can easy be calculate, so we also know how to use the current position's step length, exhaust it or prematurely stop at which postion. */
