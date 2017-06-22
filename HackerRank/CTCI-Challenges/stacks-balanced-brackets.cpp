// A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].

// Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) occurs to the left of a closing bracket
// (i.e., ), ], or }) of the exact same type. There are three types of matched pairs of brackets: [], {}, and ().

// A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For example, {[(])} is not balanced
// because the contents in between { and } are not balanced. The pair of square brackets encloses a single, unbalanced opening bracket,
// (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ].

// By this logic, we say a sequence of brackets is considered to be balanced if the following conditions are met:
// It contains no unmatched brackets.
// The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.

// Given n strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, print YES on a new line; otherwise, print NO on a new line.

bool matchingPair(char a, char b) {
    if((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']')) {
        return true;
    }
    return false;
}

bool is_balanced(string expression) {
    stack<int> res;
    for(int i = 0; i < expression.length(); i++) {
        if(expression[i] == '{' || expression[i] == '[' || expression[i] == '(') {
            res.push(expression[i]);
        } else {
            if(res.empty()) {return false;}
            if(matchingPair(res.top(), expression[i])) {
                res.pop();
            } else {
                return false;
            }
        }
    }

    if(res.empty()) {
      return true;
    } else {
      return false;
    }
}
