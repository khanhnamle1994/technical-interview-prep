// A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively.

// The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

// For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

// The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

// For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
  vector<pair<int, int>> res;
  int cur=0, cur_X, cur_H =-1,  len = buildings.size();
  priority_queue< pair<int, int>> liveBlg; // first: height, second, end time

  while(cur<len || !liveBlg.empty())
  { // if either some new building is not processed or live building queue is not empty
      cur_X = liveBlg.empty()? buildings[cur][0]:liveBlg.top().second; // next timing point to process

      if(cur>=len || buildings[cur][0] > cur_X)
      { //first check if the current tallest building will end before the next timing point
            // pop up the processed buildings, i.e. those  have height no larger than cur_H and end before the top one
          while(!liveBlg.empty() && ( liveBlg.top().second <= cur_X) ) liveBlg.pop();
      }
      else
      { // if the next new building starts before the top one ends, process the new building in the vector
          cur_X = buildings[cur][0];
          while(cur<len && buildings[cur][0]== cur_X)  // go through all the new buildings that starts at the same point
          {  // just push them in the queue
              liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
              cur++;
          }
      }

      cur_H = liveBlg.empty()?0:liveBlg.top().first; // outut the top one
      if(res.empty() || (res.back().second != cur_H) ) res.push_back(make_pair(cur_X, cur_H));
  }
  return res;
}

// The idea is to do line sweep and just process the buildings only at the start and end points. The key is to use a priority queue to save all the buildings that are still “alive”. The queue is sorted by its height and end time (the larger height first and if equal height, the one with a bigger end time first). For each iteration, we first find the current process time, which is either the next new building start time or the end time of the top entry of the live queue. If the new building start time is larger than the top one end time, then process the one in the queue first (pop them until it is empty or find the first one that ends after the new building); otherswise, if the new building starts before the top one ends, then process the new building (just put them in the queue). After processing, output it to the resulting vector if the height changes. Complexity is the worst case O(NlogN)
