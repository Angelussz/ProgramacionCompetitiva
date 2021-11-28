#include <bits/stdc++.h>

using namespace std;

int x,y,z;

struct epc {
    int x, y, z;
};

bool dentroDungeon(int x2, int y2, int z2) {
    return (x2 >= 0 && y2 >= 0 && y2 >= 0 && x2 < x && y2 < y && z2 < z);
}

int main() {
    while(cin >> x >> y >> z) {
        epc s, e;

        if(x == 0 || y == 0 || z == 0) {
            break;
        }

        vector<vector<vector<int>>> select(x);
        for(auto& i : select) {
            i.resize(y, vector<int>(z, -2));
        }

        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
                for(int k = 0; k < z; k++) {
                    char c;
                    cin >> c;
                    if(c == '#') {
                        select[i][j][k] = -1;
                    }
                    if(c == 'S') {
                        s.x = i;
                        s.y = j;
                        s.z = k;
                    }
                    if(c == 'E') {
                        e.x = i;
                        e.y = j;
                        e.z = k;
                    }
                }
            }
        }

     
        queue<epc> q;
        q.push(s);
        select[s.x][s.y][s.z] = 0;

        while(!q.empty()) {
            epc c = q.front();
            q.pop();

            if(dentroDungeon(c.x-1,c.y,c.z) && select[c.x-1][c.y][c.z] == -2) {
                select[c.x-1][c.y][c.z] = select[c.x][c.y][c.z] + 1;
                q.push({c.x-1,c.y,c.z});
            }
            if(dentroDungeon(c.x+1,c.y,c.z) && select[c.x+1][c.y][c.z] == -2) {
                select[c.x+1][c.y][c.z] = select[c.x][c.y][c.z] + 1;
                q.push({c.x+1,c.y,c.z});
            }
            if(dentroDungeon(c.x,c.y-1,c.z) && select[c.x][c.y-1][c.z] == -2) {
                select[c.x][c.y-1][c.z] = select[c.x][c.y][c.z] + 1;
                q.push({c.x,c.y-1,c.z});
            }
            if(dentroDungeon(c.x,c.y+1,c.z) && select[c.x][c.y+1][c.z] == -2) {
                select[c.x][c.y+1][c.z] = select[c.x][c.y][c.z] + 1;
                q.push({c.x,c.y+1,c.z});
            }
            if(dentroDungeon(c.x,c.y,c.z-1) && select[c.x][c.y][c.z-1] == -2) {
                select[c.x][c.y][c.z-1] = select[c.x][c.y][c.z] + 1;
                q.push({c.x,c.y,c.z-1});
            }
            if(dentroDungeon(c.x,c.y,c.z+1) && select[c.x][c.y][c.z+1] == -2) {
                select[c.x][c.y][c.z+1] = select[c.x][c.y][c.z] + 1;
                q.push({c.x,c.y,c.z+1});
            }
        }

        if(select[e.x][e.y][e.z] < 0) {
            cout << "Trapped!" << endl;
        }
        else {
            cout << "Escaped in " << select[e.x][e.y][e.z] << " minute(s)." << endl;
        }
    }
}