class Solution {
    int n,m;
    bool validar(int i,int j)
    {
        if(i<0 || i>=n|| j<0 || j>=m)
            return false;
        
        return true;
    }
    int inic[3]={-1,0,1};
    int prof[1001][1001];
    int asist(vector<vector<int>>&grid,int x,int y)
    {
       if(!validar(x,y))
         return 0;
        if(prof[x][y]!=-1)
         return prof[x][y];
        int res=INT_MAX;
        int sum=0;
        for(int i=0;i<3;i++)
        {
            if(validar(x,y+inic[i]))
            {
                int newy=y+inic[i];
                sum=grid[x][y]+asist(grid,x+1,newy);
                res=min(res,sum);
            }
        }
        return prof[x][y]=res;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(prof,-1,sizeof(prof));
        n=matrix.size();
        m=matrix[0].size();
        int res=INT_MAX;
        for(int i=0;i<m;i++)
        {
            res=min(res,asist(matrix,0,i));
        }
        return res;
    }
};