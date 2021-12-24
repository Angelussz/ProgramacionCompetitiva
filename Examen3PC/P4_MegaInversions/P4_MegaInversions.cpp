#include <bits/stdc++.h>

using namespace std;



void increment(vector<long long>& f, long long i, long long d) {
    for(; i < f.size(); i |= i+1) {
        f[i] += d;
    }
}


long long sumar(vector<long long>& f, long long i) {
    long long total = 0;
    for(; i > 0; i &= i-1) {
        total += f[i-1];
    }
    return total;
}


long long contar(vector<long long>& f, long long i) {
    return sumar(f, f.size()) - sumar(f, i);
}

int main() {
    long long n;
    cin >> n;

    vector<long long> f1(n+1, 0);
    vector<long long> f2(n+1, 0);
    vector<long long> f3(n+1, 0);

    for(long long i = 0; i < n; i++) {
        int num;
        cin >> num;
        long long s1 = contar(f1, num+1);
        long long s2 = contar(f2, num+1);

        increment(f1, num, 1);
        increment(f2, num, s1);
        increment(f3, num, s2);
    }

    cout << contar(f3, 0) << endl;
}