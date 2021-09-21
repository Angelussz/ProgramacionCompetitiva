#include <bits/stdc++.h>
using namespace std;

int Pivote(vector<int> arr, int n){
    int i = 0;
    for (; i < n+1; i++)
    {
        if (arr[i-1] == arr[n] - arr[i])
        {
            break;
        }
    }
    return i-1;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n,num;
    vector<int> A,B;
    for (int i = 0; i < n; i++)
    {
        cin>>num;
        A.push_back(num);
    }
    int n2 = A.size();
    B.push_back(0);
    for (int i = 0; i < n2; i++)
    {
        B.push_back(B[i]+A[i]);
    }
    int k = Pivote(B,n2);

    if (k<n2){
        cout<<"Pivote: "<<k<<"\n";
    }
    else
    {
        cout<<"No hay pivote\n";
    }

    return 0;
}