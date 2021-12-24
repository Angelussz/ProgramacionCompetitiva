#include <bits/stdc++.h>
using namespace std;

vector<long> va, vb;

void collazt(long& a) {
    if (a % 2 == 0) a /= 2;
    else a = 3 * a + 1;
}

void comb(long n, vector<long>& vec) {
    do {
        vec.push_back(n);
        if (n == 1) return;
        collazt(n);
    } while (1);
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    long n, m;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        va.clear();
        vb.clear();
        comb(n, va);
        comb(m, vb);

        long ans = 1;
        while (!va.empty() && !vb.empty() && va.back() == vb.back()) {
            ans = va.back();
            va.pop_back();
            vb.pop_back();
        }
        cout << n << " needs " << va.size() << " steps, ";
        cout << m << " needs " << vb.size() << " steps, ";
        cout << "they meet at " << ans << '\n';
    }

    

    return 0;
}