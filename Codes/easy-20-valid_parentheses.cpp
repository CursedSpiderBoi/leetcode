// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"
// Output: true

// Example 2:

// Input: s = "()[]{}"
// Output: true

// Example 3:

// Input: s = "(]"
// Output: false


class Solution {
public:
	bool isValid(string s) {
		stack<char> yes;
		yes.push(s[0]);
		for (int i = 1; s[i] != NULL; i++) {
            if(yes.empty()&&(s[i]==']'||s[i]=='}'||s[i]==')'))
                return false;
			if ((s[i] == ')' && yes.top()=='(')||(s[i] == ']' && yes.top()=='[')||(s[i] == '}' && yes.top()=='{')) {
				yes.pop();
			}
			else {
				yes.push(s[i]);
			}
		}
		return yes.empty();
	}
};
