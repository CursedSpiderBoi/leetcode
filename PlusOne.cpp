class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        while(n>=0){
        	if(n==digits.size()-1){
        		digits[n]=digits[n]+1;
			}
        	if(digits[n]==10){
        		digits[n]=0;
                if(n!=0){
                    digits[n-1]+=1;
                }
                if(n==0){
                	digits.insert(digits.begin(),1);
				}
			}
			n--;
		}
		return digits;
    }
};
