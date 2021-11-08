class Solution {
public:
    
    void dfs(int i,int j,vector<vector<int>>& image,int newColor,int oldColor){
        if(i<0 ||i>=image.size() ||j<0 ||j>=image[0].size() || image[i][j]!=oldColor) return;
        image[i][j]=newColor;
        dfs(i+1,j,image,newColor,oldColor);
        dfs(i,j+1,image,newColor,oldColor);
        dfs(i-1,j,image,newColor,oldColor);
        dfs(i,j-1,image,newColor,oldColor);
    }
     
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor=image[sr][sc];
        if(oldColor==newColor) return image;
        dfs(sr,sc,image,newColor,oldColor);
        return image;
    }
    
};