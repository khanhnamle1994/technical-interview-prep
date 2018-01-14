// Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

int hIndex(vector<int>& citations) {
  int left = 0, len = citations.size(), right = len-1,  mid;
  while(left <= right)
  {
      mid = left + (right - left) / 2;
      if(citations[mid] >= (len - mid)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
  }
  return len - left;
}
