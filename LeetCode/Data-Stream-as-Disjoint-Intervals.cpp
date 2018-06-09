// Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

/* For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:
[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7] */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

unordered_set<int> visited;
unordered_map<int, pair<int, int>> borders;

/** Initialize your data structure here. */
SummaryRanges() {

}

void addNum(int val) {
    // visited is for handling new incomings that are inside ranges
    if (visited.find(val) != visited.end()) {
        return;
    }
    visited.insert(val);

    // check if val-1 and val+1 are known borders
    // then perform either merge, attach, or create new range
    auto foundLower = borders.find(val - 1);
    auto foundUpper = borders.find(val + 1);
    if (foundLower != borders.end() && foundUpper != borders.end()) {
        // merge
        int lowerLower = foundLower->second.first;
        int lowerUpper = foundLower->second.second;
        int upperLower = foundUpper->second.first;
        int upperUpper = foundUpper->second.second;

        if (lowerLower != lowerUpper) {
            // dont erase for single-point range
            borders.erase(lowerUpper);
        }
        if (upperLower != upperUpper) {
            borders.erase(upperLower);
        }

        borders[lowerLower].second = upperUpper;
        borders[upperUpper].first = lowerLower;
    } else if (foundLower != borders.end()) {
        // attach
        int lowerLower = foundLower->second.first;
        int lowerUpper = foundLower->second.second;
        if (lowerLower != lowerUpper) {
            // dont erase for single-point range
            borders.erase(lowerUpper);
        }
        borders[lowerLower].second = val;
        borders[val] = make_pair(lowerLower, val);
    } else if (foundUpper != borders.end()) {
        int upperLower = foundUpper->second.first;
        int upperUpper = foundUpper->second.second;
        if (upperLower != upperUpper) {
            borders.erase(upperLower);
        }
        borders[upperUpper].first = val;
        borders[val] = make_pair(val, upperUpper);
    } else {
        // new
        borders[val] = make_pair(val, val);
    }

}

vector<Interval> getIntervals() {
    vector<int> rangeKeys;
    for (auto& rangeDef : borders) {
        int currKey = rangeDef.first;
        if (rangeDef.second.first == rangeDef.second.second) {
            // single element range
            rangeKeys.push_back(currKey);
        } else if (currKey == rangeDef.second.first) {
            // otherwise only pick lower border to avoid duplicates
            rangeKeys.push_back(currKey);
        }
    }

    sort(rangeKeys.begin(), rangeKeys.end());

    vector<Interval> result;
    for (auto key : rangeKeys) {
        Interval oneInterval(borders[key].first, borders[key].second);
        result.push_back(oneInterval);
    }
    return result;
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
