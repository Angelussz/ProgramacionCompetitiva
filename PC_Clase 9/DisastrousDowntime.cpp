#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,k;
    cin >> n >> k;
    vector<int> serv(n);
    vector<int> difer(n);
    int limite;
    double ans;
    limite = n-1;
    
    for (size_t i = 0; i < n; i++)
    {
        cin >> serv[i];        
    }

    difer[0]++;

    for (size_t i = 0; i < n-1; i++)
    {
        if(serv[i] + 1000 <= serv[limite]){
            difer[i+1]--;
        }
        else{
            difer[i+1]++;
        }
    }

    for (size_t i = 1; i < n; i++)
    {
        difer[i]+=difer[i-1];
    }

    sort(difer.begin(), difer.end(), greater<int>());
    
    ans = difer[0];
    ans = ans/k;
    cout << ceil(ans) << endl;

    return 0;
}