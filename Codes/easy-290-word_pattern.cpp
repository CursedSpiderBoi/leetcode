// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

// Example 1:

// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true

// Example 2:

// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false

// Example 3:

// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string word;
        stringstream iss(s);
        while (iss >> word)
            v.push_back(word);
        if (pattern.size() != v.size())
            return false;
        unordered_map<char, string> mp;
        unordered_map<string, char> m;
        for(int i=0; i<v.size(); i++){
            if(mp.find(pattern[i]) != mp.end() && mp[pattern[i]] != v[i]) 
                return false;
            else if(m.find(v[i]) != m.end() && m[v[i]] != pattern[i]) 
                return false;
            mp[pattern[i]] = v[i];
            m[v[i]] = pattern[i];
        }
        return true;
    }
};
