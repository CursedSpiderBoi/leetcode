class Solution {
public:
    
    const int dx[4]={-1,1,0,0};
    const int dy[4]={0,0,-1,1};
    
    int maxDistance(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<r;++i)  // storing ones into queue
        {
            for(int j=0;j<c;++j){
               if(grid[i][j]==1){
                   q.push({i,j});
                   grid[i][j]=2;
               }
            }
        }
        if(q.empty() || q.size()==r*c)
			return -1;
        int count=0;int max=-1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto node=q.front();
                q.pop();
              	for(int i=0;i<4;++i){
                   int next_i=node.first+dx[i];
                   int next_j=node.second+dy[i];
              	if(next_i>=0 && next_j>=0 && next_i<r && next_j<c  ){
                    if(grid[next_i][next_j]==0){  
                    	grid[next_i][next_j]=2;
                    	q.push({next_i,next_j});   
                        }
                    } 
                }    
            }
            max++;
        }
       return max;
        
    }
};
