class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        int count=0;
        for(int i=0;i<magazine.length(); i++){
            if(ransomNote[count]==magazine[i]){
                count++;
            }
            if(count==ransomNote.length())
                break;
        }
        return count==ransomNote.length();
    }
};
