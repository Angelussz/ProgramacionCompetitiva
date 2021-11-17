#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r,c;
    cin>>r>>c;
    
    char tipos[r][c+1];
    
    for (int i = 0; i < r; i++){
      scanf("%s", tipos[i]);

    } 
    
    int total = r * c;
    int sigGrupo = 1;
    int *group = (int*)calloc((size_t)total, sizeof(int));
    int one = 1;

    stack<pair<int,int>> form{};


    int q;
    cin>>q;
    

    while (q--)
    {
        short r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        r1--; c1--; r2--; c2--;
        int dim_one_1 = r1 * c + c1;
        int dim_one_2 = r2 * c + c2;

        if (dim_one_1 == dim_one_2){
            if (tipos[r1][c1] == '1')
            {
                cout<<"decimal\n";
            }else{
                cout<<"binary\n";
            }
            
        }
        else if (group[dim_one_1] == 0 && group[dim_one_2] == 0)
        {
            // DFS
            form.push({r1,c1});
            while (!form.empty())
            {
                pair<int,int> current = form.top();
                form.pop();
                short curr_x = current.first;
                short curr_y = current.second;
                char curr_val = tipos[curr_x][curr_y];
                int dim_one = curr_x * c + curr_y;
                if (group[dim_one]) continue;
                group[dim_one] = sigGrupo;
                if (curr_x > 0 && tipos[curr_x-1][curr_y] == curr_val && !group[(curr_x-1)*c+curr_y]) form.push({curr_x-one, curr_y});
                if (curr_x < r - 1 && tipos[curr_x+1][curr_y] == curr_val && !group[(curr_x+1)*c+curr_y]) form.push({curr_x+one, curr_y});
                if (curr_y > 0 && tipos[curr_x][curr_y-1] == curr_val && !group[curr_x*c+curr_y-1]) form.push({curr_x, curr_y-one});
                if (curr_y < c - 1 && tipos[curr_x][curr_y+1] == curr_val && !group[curr_x*c+curr_y+1]) form.push({curr_x, curr_y+one});
            }
            sigGrupo++;
            printf(group[dim_one_2] ? (tipos[r1][c1] == '1' ? "decimal\n" : "binary\n") : ("neither\n"));
        }
        else if (tipos[r1][c1] != tipos[r2][c2]) printf("neither\n");
        else if (group[dim_one_1] == group[dim_one_2]) printf(tipos[r1][c1] == '1' ? "decimal\n" : "binary\n");
        else printf("neither\n");
    }

    return 0;
}



    