class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
	    vector<int>pref(k,0);
	    int sum=0;
	    pref[0]++;
	    int rem;
	    for(int i=0;i<n;i++){
	        sum+=nums[i];
	        rem=(sum%k+k)%k;
	        count+=pref[rem];
	        pref[rem]++;
	    }
	    return count;
    }
};
