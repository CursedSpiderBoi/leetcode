class Solution {
public:
    int strStr(string haystack, string needle) {
        int start=0;
        for(int i=0;haystack[i]!=NULL;i++){
            if(haystack[i]==needle[0]){
                start=0;
                for(int j=0;needle[j]!=NULL;j++){
                    if(needle[j]==haystack[i+j]){
                        start++;
                    }
                    else{
                        break;
                    }
                }
                if(start==needle.length())
                    return i;
            }
        }
        return -1;
    }
};
