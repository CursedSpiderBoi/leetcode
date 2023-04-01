class Solution {
public:
    int search(vector<int>& v, int k) {
        int i =0,j=v.size()-1,mid;
        while(i<=j){
            mid = (j-i)/2+i;
            if(v[mid]>k)
                j = mid-1;
            else if(v[mid]<k)
                i = mid+1;
            else return mid;
        }
        return -1;
    }
};
