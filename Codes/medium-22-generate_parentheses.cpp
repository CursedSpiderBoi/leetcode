// You are given n pairs of parentheses.

// Write a function to generate all combinations of well-formed parentheses(i.e., closed pair '()').

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:

// Input: n = 1
// Output: ["()"]

class Solution {
    //need improvement
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
    void help(int left,int right,string duh,vector<string> &ans){
        if(left==0&&right==0){
            if(isValid(duh)){
                ans.push_back(duh);
            }
        }
        if(left>0)
            help(left-1,right,duh+'(',ans);
        if(right>0)
            help(left,right-1,duh+')',ans);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        help(n,n,"",ans);
        return ans;
    }
};
