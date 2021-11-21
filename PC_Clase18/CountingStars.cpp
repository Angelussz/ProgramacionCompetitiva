#include <bits/stdc++.h>
using namespace std;

void ToNeighbors(vector<vector<char>>& stars,int i, int j,int m,int n) {
 
    stack<pair<int,int>> counti{};
    counti.push({i,j});
    stars[i][j] = '#';
    vector<int> Xs ={-1, 0, 1, 0}; 
    vector<int> Ys ={0, -1, 0, 1};

    while (!counti.empty()) {
        
        pair<int,int> current = counti.top();
        counti.pop();
        int r = current.first;
        int c = current.second;

        for (int k = 0; k < 4; k++) {
                
            int ir = r + Xs[k];
            int jc = c + Ys[k];
            if ( ir >= 0 && ir < m && jc >= 0 && jc < n){
                if (stars[ir][jc] == '-')
                {
                    counti.push({ir,jc});
                    stars[ir][jc] = '#';
                }
            }
        }
    }
}



int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m=0;
    int n=0;
    int npr = 0;
    

    while(cin>>m && cin>>n){
        
        npr++;
        string line;
        vector<vector<char>> stars;

        int n_inpt = 0;
        while (n_inpt<m)
        {
            cin>>line;
            
            vector<char> col_(n);
            for (size_t i = 0; i < n; i++) col_[i] = (line[i]); 
            stars.push_back(col_);
            n_inpt++; 
        }
        
        int cnt = 0;
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (stars[i][j] == '-')
                {
                    cnt++;
                    ToNeighbors(stars,i,j,m,n);
                }
                
            }
            
        }
        cout<<"Case "<<npr<<": "<<cnt<<"\n";
        
    }
    
    return 0;
    
}