//uses sliding window
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        if(s.size() < p.size()) 
            return {};
        vector<int> anagram(26,0);
        vector<int> window(26,0);
        for(int i=0;i<p_len;i++){
            anagram[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        vector<int> ans;
        if(anagram == window)
            ans.push_back(0);
        for(int i=p_len;i<s_len;i++){
            window[s[i-p_len] - 'a']--;
            window[s[i] - 'a']++;
            if(anagram == window) 
                ans.push_back(i-p_len+1);
        }
        return ans;
    }
}; 
