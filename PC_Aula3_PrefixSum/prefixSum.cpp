#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,num;
    vector<int> A,B;
    B.push_back(0);

    cin>>n;
    while (n--)
    {
        cin>>num;
        A.push_back(num);
        B.push_back(B.back()+num);

    }

    
    
    return 0;
}