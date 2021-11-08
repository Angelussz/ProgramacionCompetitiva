class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& image,int newColor,int Colorant){
        if(i<0 ||i>=image.size() ||j<0 ||j>=image[0].size() || image[i][j]!=Colorant) return;
        image[i][j]=newColor;
        dfs(i+1,j,image,newColor,Colorant);
        dfs(i,j+1,image,newColor,Colorant);
        dfs(i-1,j,image,newColor,Colorant);
        dfs(i,j-1,image,newColor,Colorant);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int Colorant=image[sr][sc];
        if(Colorant==newColor) return image;
        dfs(sr,sc,image,newColor,oldColor);
        return image;
    }
};