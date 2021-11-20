class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        if (grid.empty() 
            || grid.size() == 0 
            || grid[0].size() == 0) 
            return 0;
        
        int n = grid.size();
        
        int min1, min2, minCol = 0;
        for (int i = n - 2; i >= 0; i--) {
            min1 = INT_MAX;
            min2 = INT_MAX;
            
            for (int j = 0; j < n; j++) {
                if (grid[i + 1][j] < min1) {
                    min2 = min1;
                    min1 = grid[i + 1][j];
                    minCol = j;
                } else if (grid[i + 1][j] < min2) {
                    min2 = grid[i + 1][j];
                }
            }
            
            for (int j = 0; j < n; j++) {
                if (j == minCol) grid[i][j] += min2;
                else grid[i][j] += min1;
            }
        }
        
        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
           result = min(result, grid[0][i]);
        }
        
        return result;
    }
};