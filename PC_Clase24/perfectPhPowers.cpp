#include <bits/stdc++.h>
using namespace std;

int 
main(int argc, char const *argv[])
{
    long double n;
    while (cin >> n && n != 0){
        bool flag = false;
        if (n < 0) flag = true;
        n = abs(n);
        for (long long i = sqrt(n)+1; i >= 1; i--){
            if (flag && i%2 == 0) continue;
            long double power = 1/long double(i);
            long double val = pow(n,power);
            long double diff = abs(val - floor(val));
            if (diff < .00001){
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}