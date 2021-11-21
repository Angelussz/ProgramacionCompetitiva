#include <bits/stdc++.h>
using namespace std;

void ToNeighbors(vector<vector<char>>& banne,int i, int j,int m,int n) {
    stack<pair<int,int>> partAme{};
    partAme.push({i,j});
    banne[i][j] = '.';
    vector<int> Xs ={-1, 0, 1, 0, 1, -1, 1, -1}; 
    vector<int> Ys ={0, -1, 0, 1, 1, 1, -1, -1};

    while (!partAme.empty()) {
        
        pair<int,int> current = partAme.top();
        partAme.pop();
        int r = current.first;
        int c = current.second;
       

        for (int k = 0; k < 8; k++) {
                
            int ir = r + Xs[k];
            int jc = c + Ys[k];
           
            if ( ir >= 0 && ir < m && jc >= 0 && jc < n){
                if (banne[ir][jc] == '#')
                {
                    partAme.push({ir,jc});
                    banne[ir][jc] = '.';
                }
            }
        }
    }
}



int main ()
{   
    int m,n;
    cin>>m>>n;

    string line;
    vector<vector<char>> banne;

    int entra = 0;
    while (entra<m)
    {
        cin>>line;
        // cout<<line<<"\n";
        vector<char> aux(n);
        for (size_t i = 0; i < n; i++) aux[i] = (line[i]); 
        banne.push_back(aux);
        entra++; 
    }
    
    int cnt = 0;
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (banne[i][j] == '#')
            {
                cnt++;
                ToNeighbors(banne,i,j,m,n);
            }
            
        }
        
    }
    cout<<cnt<<"\n";
}