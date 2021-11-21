class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows=dungeon.size();
        if(rows==0)
            return 0;
        int cols=dungeon[0].size();
        vector<vector<int> > prof(rows,vector<int> (cols,0));
        prof[rows-1][cols-1]=max(1,1-dungeon[rows-1][cols-1]);
    
        for(int i=rows-2;i>=0;i--){
            prof[i][cols-1]=max(prof[i+1][cols-1]-dungeon[i][cols-1],1);
        }
        for(int i=cols-2;i>=0;i--){
            prof[rows-1][i]=max(prof[rows-1][i+1]-dungeon[rows-1][i],1);
        }
    
        for(int i=rows-2;i>=0;i--){
            for(int j=cols-2;j>=0;j--){
                int val1=max(prof[i+1][j]-dungeon[i][j],1);
                int val2=max(prof[i][j+1]-dungeon[i][j],1);
                prof[i][j]=min(val1,val2);
            }
        }
        return prof[0][0];
    }
};