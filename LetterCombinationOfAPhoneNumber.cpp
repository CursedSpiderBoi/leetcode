class Solution {
    void get_results(vector<string> &res, string nah, string &digits, int i){
        if(i>=digits.size()){
            res.push_back(nah);
            return;
        }
        else{
            if(digits[i]=='2'){
                get_results(res,nah+'a',digits,i+1);
                get_results(res,nah+'b',digits,i+1);
                get_results(res,nah+'c',digits,i+1);
            }
            if(digits[i]=='3'){
                get_results(res,nah+'d',digits,i+1);
                get_results(res,nah+'e',digits,i+1);
                get_results(res,nah+'f',digits,i+1);
            }
            if(digits[i]=='4'){
                get_results(res,nah+'g',digits,i+1);
                get_results(res,nah+'h',digits,i+1);
                get_results(res,nah+'i',digits,i+1);
            }
            if(digits[i]=='5'){
                get_results(res,nah+'j',digits,i+1);
                get_results(res,nah+'k',digits,i+1);
                get_results(res,nah+'l',digits,i+1);
            }
            if(digits[i]=='6'){
                get_results(res,nah+'m',digits,i+1);
                get_results(res,nah+'n',digits,i+1);
                get_results(res,nah+'o',digits,i+1);
            }
            if(digits[i]=='7'){
                get_results(res,nah+'p',digits,i+1);
                get_results(res,nah+'q',digits,i+1);
                get_results(res,nah+'r',digits,i+1);
                get_results(res,nah+'s',digits,i+1);
            }
            if(digits[i]=='8'){
                get_results(res,nah+'t',digits,i+1);
                get_results(res,nah+'u',digits,i+1);
                get_results(res,nah+'v',digits,i+1);
            }
            if(digits[i]=='9'){
                get_results(res,nah+'w',digits,i+1);
                get_results(res,nah+'x',digits,i+1);
                get_results(res,nah+'y',digits,i+1);
                get_results(res,nah+'z',digits,i+1);
            }
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits==""){
            return ans;
        }
        get_results(ans,"",digits,0);
        return ans;
    }
};
