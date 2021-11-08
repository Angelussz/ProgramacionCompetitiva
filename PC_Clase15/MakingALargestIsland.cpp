class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int& area, int index) {
        if (i < 0 || i >= n || j < 0 || j >= n) return;
        if (grid[i][j] != 1) return;
        grid[i][j] = index;
        ++area;
        dfs(grid, i - 1, j, n, area, index);
        dfs(grid, i + 1, j, n, area, index);
        dfs(grid, i, j - 1, n, area, index);
        dfs(grid, i, j + 1, n, area, index);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int res = 0, n = grid.size();
        vector<int> areas = {-1, -1};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;
                int area = 0;
                dfs(grid, i, j, n, area, areas.size());
                areas.push_back(area);
            }
        }
        bool ceros = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) continue;
                ceros = true;
                unordered_set<int> tamanio;
                if (i > 0 && grid[i - 1][j] > 1) tamanio.insert(grid[i - 1][j]);
                if (i < n - 1 && grid[i + 1][j] > 1) tamanio.insert(grid[i + 1][j]);
                if (j > 0 && grid[i][j - 1] > 1) tamanio.insert(grid[i][j - 1]);
                if (j < n - 1 && grid[i][j + 1] > 1) tamanio.insert(grid[i][j + 1]);
                int area = 1;
                for (int index : tamanio) {
                    area += areas[index];
                }
                res = max(res, area);
            }
        }
        
        return ceros ? res : n * n;
    }
};