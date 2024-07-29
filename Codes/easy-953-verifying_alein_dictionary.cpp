// In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. 

// The order of the alphabet is some permutation of lowercase letters.

// Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

 

// Example 1:

// Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
// Output: true
// Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

// Example 2:

// Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
// Output: false
// Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

// Example 3:

// Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
// Output: false
// Explanation: The first three characters "app" match, and the second string is shorter (in size.) 
// According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).


class Solution {
    bool check(string &word1, string &word2,unordered_map<char, int> &map){
        int n= min(word1.length(), word2.length());
        for(int i=0; i<n; i++){
            if(map[word1[i]]<map[word2[i]])
                return true;
            else if(map[word1[i]]>map[word2[i]])
                return false;
        }
        return word1.size()<=word2.size();
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> map;
        for(int i=0; i< order.length(); i++)
            map[order[i]]= i+1;
        for(int i=0; i< words.size()-1; i++)    {
            if(!check(words[i], words[i+1],map)) 
                return false;
        }
        return true;
    }
};
