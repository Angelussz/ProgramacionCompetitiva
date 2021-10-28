#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums){

    
}

int main(){

    vector<int> caso{4,-1,5,2,3};
    deque<int> arrdob;
    for(int i=0;i<caso.size(); i++)
        arrdob.push_front(caso[i]);
    
    int resp = 0;
    while (!caso.empty())
    {
        int left = arrdob.back();
        int right = arrdob.front();

        if(left == -1 || right == -1){
            cout << resp <<endl;
            return 0;}
        else if(right < left){
            resp+=arrdob.front();
            arrdob.pop_front();}
        else{
            resp+=arrdob.back();
            arrdob.pop_back();
        }
    }
    cout << resp << endl;
}