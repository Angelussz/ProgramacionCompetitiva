#include <bits/stdc++.h>
using namespace std;



vector<string> arrdatos;
int n, m;
 
 
int distancia[1001][1001];
int d[1001][1001];
int dx[4] = { 0, 0, -1, 1 }; 
int dy[4] = { -1, 1, 0, 0 };
 
int main() {
    for(int i =0;i<1001;i++){
        for(int j =0;j<1001;j++){
            distancia[i][j]=-1;
          }
        }
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        string x;cin>>x;
        arrdatos.push_back(x);
        }
        int x,y,c1,c2;
        queue<vector<int>>q;
        for(int i =0;i<n;i++){
          for(int j =0;j<m;j++){
            if(arrdatos[i][j]=='M')q.push({i, j, 0});
        		if(arrdatos[i][j]=='A'){
                    c1=i;
                    c2=j;
                }
                
          }
        }
       
		x=c1;
        y=c2;
        while(!q.empty()) {
            auto curr= q.front();
            q.pop();
            int x=curr[0], y=curr[1], steps=curr[2];
            if(x < 0 || x > n - 1 || y < 0 || y > m - 1 || arrdatos[x][y]=='#' || distancia[x][y]!=-1)continue;
            distancia[x][y]=steps;
            for(int i=0;i<4;i++){
              int cx=x+dx[i], cy=y+dy[i];
              q.push({ cx, cy, steps+1});
            }
        }
        string resp;
        while(!q.empty())   q.pop();
        q.push({ x, y, 0, 0 });
        for(int i =0;i<1001;i++){
          for(int j =0;j<1001;j++){
            d[i][j]=-1;
          }
        }

        bool c = false;
        int p[n + 1][m + 1];
        memset(p, 0, sizeof(p));
        while(!q.empty()) {
            auto curr=q.front();
            q.pop();
            int x =curr[0], y =curr[1], steps =curr[2], dir =curr[3];
            if(x < 0 || x > n - 1 || y < 0 || y > m - 1 || arrdatos[x][y] == '#' || d[x][y] != -1 || (distancia[x][y] >= 0 and distancia[x][y] <= steps))
                continue;
            if(x == n - 1 || y == m - 1 || x == 0 || y == 0) {
                p[x][y] = dir;
                while(x != c1 or y != c2) {
                    if(p[x][y] == 0)    resp += 'L', y++;// path is from (x, y) to (x, y-1) so resp+='L' and (0=> {0, -1}) thats why y++.
                    else if(p[x][y] == 1) resp += 'R', y--;
                    else if(p[x][y] == 2)  resp += 'U', x++;
                    else    resp += 'D', x--;	
                }
                reverse(resp.begin(), resp.end());
                c=true;
                break;
            }
            d[x][y] = steps;
            p[x][y] = dir;
            for(int i=0;i<4;i++){
              int cx=x+dx[i], cy=y+dy[i];
              q.push({ cx, cy, steps + 1, i });
            }
            
        }
        if(c){
            cout<<"YES"<<endl<<resp.size()<<endl<<resp;
        }
        else
            cout << "NO"<<endl;
    
	return 0;
}