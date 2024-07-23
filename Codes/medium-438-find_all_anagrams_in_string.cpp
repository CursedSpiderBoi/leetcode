// You are given two strings s and p.

// Return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
//   The substring with start index = 0 is "cba", which is an anagram of "abc".
//   The substring with start index = 6 is "bac", which is an anagram of "ABC".

// Example 2:

// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
//   The substring with start index = 0 is "ab", which is an anagram of "ab".
//   The substring with start index = 1 is "ba", which is an anagram of "ab".
//   The substring with start index = 2 is "ab", which is an anagram of "ab".


class Solution {
public:
    // Uses sliding window
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
