// Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.

// Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).

/* Example 1:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [3,2,4,4],
  [1,3,2,4],
  [2,3,3,4]
]

Return true. All 5 rectangles together form an exact cover of a rectangular region.

Example 2:

rectangles = [
  [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
]

Return false. Because there is a gap between the two rectangular regions.

Example 3:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [3,2,4,4]
]

Return false. Because there is a gap in the top center.

Example 4:

rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [2,2,4,4]
]

Return false. Because two of the rectangles overlap with each other. */

struct hash_pair {
    size_t operator() (const pair<int,int> &p) const {
        return p.first + p.second * 31;
    }
};

bool isRectangleCover(vector<vector<int>>& rectangles) {
    int left = INT_MAX, right = INT_MIN, bottom = INT_MAX, top = INT_MIN, area, sum = 0;
    unordered_set<pair<int,int>, hash_pair> hash;
    for(int i = 0; i < rectangles.size(); i++) {
        if(left > rectangles[i][0]) {
            left = rectangles[i][0];
        }


        if(bottom > rectangles[i][1]) {
            bottom = rectangles[i][1];
        }


        if(right < rectangles[i][2]) {
            right = rectangles[i][2];
        }


        if(top < rectangles[i][3]) {
            top = rectangles[i][3];
        }

        if(hash.find(make_pair(rectangles[i][0], rectangles[i][1])) != hash.end()) {
            hash.erase(make_pair(rectangles[i][0], rectangles[i][1]));
        } else {
            hash.insert(make_pair(rectangles[i][0], rectangles[i][1]));
        }

        if(hash.find(make_pair(rectangles[i][0], rectangles[i][3])) != hash.end()) {
            hash.erase(make_pair(rectangles[i][0], rectangles[i][3]));
        } else {
            hash.insert(make_pair(rectangles[i][0], rectangles[i][3]));
        }

        if(hash.find(make_pair(rectangles[i][2], rectangles[i][1])) != hash.end()) {
            hash.erase(make_pair(rectangles[i][2], rectangles[i][1]));
        } else {
            hash.insert(make_pair(rectangles[i][2], rectangles[i][1]));
        }

        if(hash.find(make_pair(rectangles[i][2], rectangles[i][3])) != hash.end()) {
            hash.erase(make_pair(rectangles[i][2], rectangles[i][3]));
        } else {
            hash.insert(make_pair(rectangles[i][2], rectangles[i][3]));
        }

        area = ((rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]));
        sum += area;
    }

    if(hash.find(make_pair(left, bottom)) == hash.end() ||
       hash.find(make_pair(left, top)) == hash.end() ||
       hash.find(make_pair(right, bottom)) == hash.end() ||
       hash.find(make_pair(right, bottom)) == hash.end() ||
       hash.size() != 4) {
        return false;
    }


    if(sum != ((right - left) * (top - bottom))) {
        return false;
    }

    return true;
}
