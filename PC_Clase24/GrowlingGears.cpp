#include <bits/stdc++.h>
using namespace std;

void Sol(){

    int k;
    cin >> k;
    double max1 = -INFINITY;
    int max2 = 0;

    for (size_t i = 1; i <= k; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        double temp = (double)b/(a<<1);
        double val = -a * temp * temp + b * temp + c;

        if(val > max1){
            max1 = val;
            max2 = i;
        }
    }
    cout << max2 << endl;
    
}

int main(){

    int t;
    cin >> t;
    while (t--)
    {
        Sol();
    }
    
    return 0;
}