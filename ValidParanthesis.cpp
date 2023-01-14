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
