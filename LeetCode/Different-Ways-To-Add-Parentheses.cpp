// Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers
// and operators. The valid operators are +, - and *.

/* Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10] */

// Dynamic Programming Solution 
vector<int> diffWaysToCompute(string input) {
		unordered_map<string, vector<int>> dpMap;
		return computeWithDP(input, dpMap);
}

vector<int> computeWithDP(string input, unordered_map<string, vector<int>> &dpMap) {
		vector<int> result;
		int size = input.size();
		for (int i = 0; i < size; i++) {
			char cur = input[i];
			if (cur == '+' || cur == '-' || cur == '*') {
				// Split input string into two parts and solve them recursively
				vector<int> result1, result2;
				string substr = input.substr(0, i);
				// check if dpMap has the result for substr
				if (dpMap.find(substr) != dpMap.end())
					result1 = dpMap[substr];
				else
					result1 = computeWithDP(substr, dpMap);

				substr = input.substr(i + 1);
				if (dpMap.find(substr) != dpMap.end())
					result2 = dpMap[substr];
				else
					result2 = computeWithDP(substr, dpMap);

				for (auto n1 : result1) {
					for (auto n2 : result2) {
						if (cur == '+')
							result.push_back(n1 + n2);
						else if (cur == '-')
							result.push_back(n1 - n2);
						else
							result.push_back(n1 * n2);
					}
				}
			}
		}
		// if the input string contains only number
		if (result.empty())
			result.push_back(atoi(input.c_str()));
		// save to dpMap
		dpMap[input] = result;
		return result;
}
