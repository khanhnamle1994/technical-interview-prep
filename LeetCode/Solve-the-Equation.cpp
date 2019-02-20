/* Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.

If there is no solution for the equation, return "No solution".

If there are infinite solutions for the equation, return "Infinite solutions".

If there is exactly one solution for the equation, we ensure that the value of x is an integer.

Example 1:
Input: "x+5-3+x=6+x-2"
Output: "x=2"

Example 2:
Input: "x=x"
Output: "Infinite solutions"

Example 3:
Input: "2x=x"
Output: "x=0"

Example 4:
Input: "2x+3x-6x=x+2"
Output: "x=-1"

Example 5:
Input: "x=x+2"
Output: "No solution" */

string solveEquation(string equation) {
  int xsum = 0, numsum = 0;
	vector<pair<string, int>> sum;
	pair<string, int> v;
	bool status = true;
	bool zero = false;
	for (auto c : equation)
	{
		if (c == '+' || c == '-' || c == '=')
		{
			if (c == '+')
				status = true;
			else if(c == '-')
				status = false;
			else if (c == '=')
			{
				sum.push_back(v);
				v = std::make_pair("=", 0);
				status = true;
			}
			sum.push_back(v);
			v = std::make_pair("", 0);
			zero = false;
		}
		else if (isdigit(c))
		{
			v.second *= 10;
			if (status == true)
				v.second += c - 48;
			else
				v.second -= c - 48;
			if (v.second == 0)
				zero = true;
		}
		else if (c == 'x')
		{
			v.first = "x";
			if (zero == true)
				continue;
			if (v.second == 0)
			{
				if (status == true)
					v.second = 1;
				else
					v.second = -1;
			}
		}
	}
	sum.push_back(v);
	status = true;
	for (auto a : sum)
	{
		if (a.first == "")
		{
			if (status == true)
				numsum += a.second;
			else
				numsum -= a.second;
		}
		else if (a.first == "x")
		{
			if (status == true)
				xsum += a.second;
			else
				xsum -= a.second;
		}
		else
		{
			status = false;
		}
	}

	string s;
	if (xsum == 0 && numsum == 0)
		s = "Infinite solutions";
	else if (xsum == 0 && numsum != 0)
		s = "No solution";
	else
		s = "x=" + std::to_string(-numsum / xsum);
	return s;
}
