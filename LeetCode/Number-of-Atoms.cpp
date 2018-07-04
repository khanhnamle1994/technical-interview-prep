// Given a chemical formula (given as a string), return the count of each atom.

// An atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

// 1 or more digits representing the count of that element may follow if the count is greater than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

// Two formulas concatenated together produce another formula. For example, H2O2He3Mg4 is also a formula.

// A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are formulas.

// Given a formula, output the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

/* Example 1:
Input:
formula = "H2O"
Output: "H2O"
Explanation:
The count of elements are {'H': 2, 'O': 1}.

Example 2:
Input:
formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation:
The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.

Example 3:
Input:
formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation:
The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}. */

void compute(string& formula, std::map<string, int>& stats) {
    int n = formula.size();

    std::stack<int> stk; // factor
    stk.push(1);

    string elem; // chemical element, e.g., C, N, O, Na, Mg, Al, etc.
    int factor = 1; // number of this element, default to 1 if not otherwise specified

    for (int i = 0; i < n; ++i) {
        auto& c = formula[i];
        if (isdigit(c)) { // E.g., original 312 was reverse to 213.
            int val = 0, expo = 1;
            do {
                val += (c - '0') * expo;
                ++i; expo *= 10;
            } while (isdigit(c = formula[i]));
            factor = val; // explicit number of this element

            i -= 1;
        } else if (c == ')') {
            stk.push(factor * stk.top());
            factor = 1; //            Al(OH)3
        } else if (c >= 'A' && c <= 'Z') {
            elem += c;
            std::reverse(elem.begin(), elem.end());
            stats[elem] += factor * stk.top();
            factor = 1;
            elem.clear();
        } else if (c >= 'a' && c <= 'z') {
            elem += c;
        } else { // (c == '(') {
            stk.pop();  // Ca(OH)2
            // elem.clear();
        }
    }
}

string countOfAtoms(string formula) {
    std::map<string, int> stats;
    std::reverse(formula.begin(), formula.end());
    compute(formula, stats);
    string result;

    for (auto& kv : stats) {
        result += kv.first;
        if (kv.second > 1) {
            result += std::to_string(kv.second);
        }
    }
    return result;
}
