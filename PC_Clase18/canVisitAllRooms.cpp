class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms, int key, int visit[])
    {
        visit[key]=true;
        for(int i=0;i<rooms[key].size();i++)
        {
            if(!visit[rooms[key][i]])
            {
                dfs(rooms,rooms[key][i],visit);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        int visit[n];
    
        memset(visit,0, sizeof visit);
    
        dfs(rooms, 0, visit);
    
        for(int i=0;i<n;i++)
        {
            if(!visit[i])
            {
                return false;
            }
        }
        return true;
    }
};  