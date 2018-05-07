// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

/* Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Return the array [2, 1, 1, 0]. */

void mergeSort(vector<pair<int,int>> &inums,vector<int> &count,int l,int r){
    if(l>=r){ count[inums[l].second]=0;return;}
    int m=l+((r-l)>>1);
    mergeSort(inums,count,l,m);
    mergeSort(inums,count,m+1,r);
    int i=0,j=m+1,k=0;
    vector<pair<int,int>> merge(r-l+1);
    for(i=l;i<=m;i++){
        while(j<=r&&inums[i].first>inums[j].first){
            merge[k++]=inums[j++];
        }
        count[inums[i].second]+=j-m-1;
        merge[k++]=inums[i];
    }
    while(j<=r) merge[k++]=inums[j++];
    for(i=l;i<=r;i++) inums[i]=merge[i-l];
}

vector<int> countSmaller(vector<int>& nums) {
  vector<int> count(nums.size());
  if(nums.size()==0) return count;
  vector<pair<int,int>> inums(nums.size());
  for(int i=0;i<nums.size();i++) inums[i]=pair<int,int>(nums[i],i);
  mergeSort(inums,count,0,nums.size()-1);
  return count;
}
