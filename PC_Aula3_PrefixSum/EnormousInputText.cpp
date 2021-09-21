#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,l,cont=0;
    cin>>n;
    cin>>k;
    while(n--){
        cin>>l;
        cont = (l%k == 0) ? cont+1:cont;
    }
    cout<<cont<<"\n";
    return 0;
}