// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

/* Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5 */

/* Design a data structure that supports the following two operations:
>> void addNum(int num) - Add a integer number from the data stream to the data structure.
>> double findMedian() - Return the median of all elements so far.

For example:
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2 */

/** initialize your data structure here. */
multiset<int> s1;
multiset<int> s2;

MedianFinder() {
  s1.clear();
  s2.clear();
}

void addNum(int x) {
  //Adding Number to first set only if its empty or if number less than max element of set 1
  if(s1.size() == 0 || x < *(prev(s1.end())) ) {
    s1.insert(x);
  } else {
    s2.insert(x);
  }

  //Adjusting sizes so that difference is never greater than 1
  if(abs(s1.size() - s2.size()) > 1) {
    if(s1.size() > s2.size()) {
        s2.insert(*(prev(s1.end())));
        s1.erase(prev(s1.end()));
    }
    else {
        s1.insert(*(s2.begin()));
        s2.erase(s2.begin());
    }
  }
}

double findMedian() {
  double med;

  //check if odd or even number of elements
  if(abs(s1.size() - s2.size()) > 0){
    if(s1.size() > s2.size()){
        med = *(prev(s1.end()));
    }
    else {
      med=*(s2.begin());
    }
  } else {
    med = 0.5 * (*(prev(s1.end())) + *(s2.begin()));
  }
  return med;
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
