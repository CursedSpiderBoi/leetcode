class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) { // If current cell is land
                    perimeter += 4; // Each land cell contributes 4 sides to perimeter
                    // Check left neighbor
                    if (j > 0 && grid[i][j - 1] == 1)
                        perimeter -= 2; // Subtract 2 if left neighbor is land
                    // Check top neighbor
                    if (i > 0 && grid[i - 1][j] == 1)
                        perimeter -= 2; // Subtract 2 if top neighbor is land
                }
            }
        }
        
        return perimeter;
    }
};

// If the neighbor to the left or above is also land, it means these two land cells share a side. So, we subtract 2 from the perimeter for each shared side. We subtract 2 because when two land cells share a side, only one side of each cell contributes to the perimeter. Hence, subtracting 2 from the total accounts for both shared sides.
