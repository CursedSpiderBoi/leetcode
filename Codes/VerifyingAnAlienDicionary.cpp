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
