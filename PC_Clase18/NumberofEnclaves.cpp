class Solution {
public:
    void dfs(vector<vector<int>> &board, int i, int j, int m, int n, int &boundaryOnes) {
        if (i<0 || j<0 || i>=m || j>=n || board[i][j] != 1) {
            return ;
        }
    
        boundaryOnes++;
        board[i][j] = 2;
        dfs(board, i+1, j, m, n, boundaryOnes);
        dfs(board, i, j+1, m, n, boundaryOnes);
        dfs(board, i-1, j, m, n, boundaryOnes);
        dfs(board, i, j-1, m, n, boundaryOnes);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int cont = 0;
        int m = grid.size();
        int n = grid[0].size();
    
        for (int i=0 ; i<m ; i++) {
            for (int j=0 ; j<n ; j++) {
                if (grid[i][j] == 1)
                    cont++;
            }
        }
            
        int boundaryOnes = 0;
        for (int i=0 ; i<m ; i++) {
            if (grid[i][0] == 1)
                dfs(grid, i, 0, m, n, boundaryOnes);
            if (grid[i][n-1] == 1)
                dfs(grid, i, n-1, m, n, boundaryOnes);
        }
    
        for (int i=0 ; i<n ; i++) {
            if (grid[0][i] == 1)
                dfs(grid, 0, i, m, n, boundaryOnes);
            if (grid[m-1][i] == 1)
                dfs(grid, m-1, i, m, n, boundaryOnes);
        }
    
        return cont-boundaryOnes;
    }
};