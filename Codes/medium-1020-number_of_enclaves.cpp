// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

// Example 1:


// Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 3
// Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
// Example 2:


// Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
// Output: 0
// Explanation: All 1s are either on the boundary or can reach the boundary.


class Solution {
    void dfs(vector<vector<int>> &grid,int i,int j){
        int x[4]={0,0,1,-1};
        int y[4]={1,-1,0,0};
        stack<vector<int>> q;
        vector<int> cords(2);
        cords[0]=i;
        cords[1]=j;
        q.push(cords);
        while(!q.empty()){
            cords=q.top();
            q.pop();
            for(int k=0;k<4;k++){
                if (cords[0] + x[k] >= 0 && cords[0] + x[k] < grid.size() && cords[1] + y[k] >= 0 && cords[1] + y[k] < grid[0].size()) {
                    if ( grid[cords[0] + x[k]][cords[1] + y[k]] == 1)
                        q.push({cords[0] + x[k], cords[1] + y[k]});
                }
            }
            grid[cords[0]][cords[1]]=0;
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid)  {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if(i==0 || i==grid.size()-1 || j==0 || j== grid[0].size()-1){
                    if(grid[i][j]==1)
                        dfs(grid,i,j);
                    continue;
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                    count++;
            }
        }
        return count;
    }
}; 
