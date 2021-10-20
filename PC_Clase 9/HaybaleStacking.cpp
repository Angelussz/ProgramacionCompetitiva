#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> eno(n);
    while (k--)
    {
        int A, B;
        cin >> A >> B;

        for (size_t i = A - 1; i <= B - 1 ; i++)
        {
            eno[i]++;
        }
      
    }
    sort(eno.begin(), eno.end());
    int media = n/2;
    cout << eno[media];
    return 0;
}