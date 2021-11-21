class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mups(m,vector<int> (n,0));
    
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0) mups[i][j] = 1;
                else if( i == 0)  mups[i][j] = mups[i][j-1];
                else if( j == 0)  mups[i][j] = mups[i-1][j];
                else mups[i][j] = mups[i-1][j] + mups[i][j-1];
            }
        
        }
        return mups[m-1][n-1];
    }
};