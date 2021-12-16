#include <bits/stdc++.h>
using namespace std;

long long int fact(long long int n) {
    vector<long long int> result(10000);
    if (n >= 0) {
      result[0] = 1;
      for (long long int i = 1; i <= n; ++i) {
         result[i] = i * result[i - 1];
      }
      return result[n];
   }
}

void Sol(){

    long long int n;
    cin >> n;
    long long int ans = fact(n);
    
    long long int sz = trunc(log10(ans))+1;
    cout << sz << endl;

}

int main(){

    Sol();

    return 0;
}