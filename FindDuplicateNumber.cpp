//floyd cycle detection
class Solution {
public:
    int findDuplicate(vector<int>& costs) {
        int i=0,j=0;
        while(true){
            i=costs[i];
            j=costs[costs[j]];
            if(i==j)
                break;
        }
        j=0;
        while(true){
            i=costs[i];
            j=costs[j];
            if(i==j)
                return i;
        }
        return j;
    }
};
