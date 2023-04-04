class Solution {
public:
    int partitionString(string s) {
        int ans=0;
        unordered_map<char,int> m1;
        for(int i=0;i<s.size();i++){
            if(m1[s[i]]){
                ans++;
                for(int j=0;j<m1.size();j++)
                    m1[j]=0;
            }
            m1[s[i]]++;
        }
        return ans+1;//last string partitioning adding explicitly
    }
};
