#include <bits/stdc++.h>
using namespace std;
int main() {
    // read the input
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> personas(n);
    for (int i = 0; i < n; i++) cin >> personas[i];
 
    // use bit-masking to compute the profun table
    int limit = 1 << n;
    vector<pair<long long, long long>> profun(limit); // (numberOfRides, totalWeightOfLastRide)
    profun[0] = {1, 0};
 
    for (int maskbits = 1; maskbits < limit; maskbits++) {
        pair<long long, long long> resultmin = {INT_MAX, INT_MAX};
        for (int i = 0; i < n; i++) {
            if (((1 << i) & maskbits) == 0){
              continue;  
            } 
            auto difer = profun[(1 << i) ^ maskbits];
            if (difer.second + personas[i] <= x) {
                difer.second += personas[i];
            } else {
                difer.first += 1;
                difer.second = personas[i];
            }
            resultmin = min(resultmin, difer);
        }
        profun[maskbits] = resultmin;
    }
    cout << profun[limit - 1].first;
 
    return 0;
}