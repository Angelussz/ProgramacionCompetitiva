#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<vector<int>> list{{1,4,5}, {1,3,4},{2,6}};
    
    priority_queue<int,vector<int>, greater<int>> colapri; 

    for(auto &i : list){
        for(auto &j : i){
            colapri.push(j);
        }
    }

    while (!colapri.empty())
    {
        cout << colapri.top() << " ";
        colapri.pop();
    }
    cout<<endl;

    return 0;
}