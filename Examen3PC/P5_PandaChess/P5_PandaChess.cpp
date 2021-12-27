
#include <bits/stdc++.h>
using namespace std;

int n, m, d;
map<long long, unordered_set<long long>> adjlist;
map<long long, int> dist;
vector<long long> ts;
unordered_set<long long> ics;
void sortingtop(long long u) {
    dist[u] = 1;
    for (auto v : adjlist[u]) {
        if (dist[v] == 0) sortingtop(v);
    }
    ts.emplace_back(u);
}

int main() {
    cin >> n >> m >> d;
    
    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;        
        adjlist[a].insert(b);
        ics.insert(a);
        ics.insert(b);
    }
    for (auto u : ics) {
        if (dist[u] == 0) sortingtop(u);
    }
    reverse(ts.begin(), ts.end());

    
    for (int i = 0; i < n; i++) {
        dist[ts[i]] = i+1;  
    }
    
    vector<int> v;
    vector<int> L(n, 0);  
    for (int i = 0; i < n; i++) {
        long long a;
        scanf("%lld", &a);
        if (dist[a] == 0) continue;
        v.push_back(dist[a]);
    }

    int k = 0;  
    for (int i = 0; i < (int) v.size(); i++) {
        int pos = lower_bound(L.begin(), L.begin() + k, v[i]) - L.begin();
        L[pos] = v[i];
        if (pos == k) {
            k++;
        }
    }
    cout << 2*(n - k) << endl;

    return 0;
}