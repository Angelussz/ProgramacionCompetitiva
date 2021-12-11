
#include<bits/stdc++.h>
using namespace std;
  
const int maxNum = 1e5+5;
int sa[maxNum], pos[maxNum], tmp[maxNum], lcp[maxNum];
int gap, N;
string segundo;
 
bool comparar(int x, int y) {
    if (pos[x] != pos[y])
        return pos[x] < pos[y];
    x += gap;
    y += gap;
    return (x < N && y < N) ? pos[x] < pos[y] : x > y;
}
 
void suffix() {
    for (int i = 0; i < N; i++)
        sa[i] = i, pos[i] = segundo[i];
 
    for (gap = 1;; gap <<= 1) {
        sort(sa, sa+N, comparar);
        for (int i = 0; i < N-1; i++)
            tmp[i+1] = tmp[i] + comparar(sa[i], sa[i+1]);
        for (int i = 0; i < N; i++)
            pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1)
            break;
    }
}
 
void crearLCP() {
    for (int i = 0, k = 0; i < N; i++) if (pos[i] != N-1) {
        int j = sa[pos[i] + 1];
        while (segundo[i + k] == segundo[j + k])
            k++;
        lcp[pos[i]] = k;
        if (k) k--;
    }
}

pair<int,int> seg[maxNum*10];
int mark[maxNum*10];
 
void push(int k) {
    if (mark[k]) {
        mark[k] = 0;
        seg[2*k].primer = seg[2*k + 1].primer = seg[k].primer/2;
        seg[2*k].segundo = seg[2*k + 1].segundo = 0;
        mark[2*k] = mark[2*k + 1] = 1;
    }   
}
 
void actualizar(int v, int a, int b, int k, int x, int y) {
    if (b < x || a > y) return;
    if (a<=x && b>=y) {
        seg[k].segundo += v;
        return;
    }
    int h = min(b,y) - max(a,x) + 1;
    push(k); 
    seg[k].primer += h*v;
    int d = (x+y)/2;
    actualizar(v, a, b, 2*k, x, d);
    actualizar(v, a, b, 2*k + 1, d + 1, y);
}
int asignar(int v, int a, int b, int k, int x, int y) {
    if (b < x || a > y) return seg[k].primer + (y - x + 1)*seg[k].segundo;
    if (a <= x && b >= y) {
        seg[k].primer = (y-x+1)*v;
        seg[k].segundo = 0;
        mark[k] = 1; 
        return seg[k].primer;
    }
    push(k); 
    int d = (x+y)/2;
    seg[2*k].segundo += seg[k].segundo,  seg[2*k + 1].segundo += seg[k].segundo;
    seg[k].segundo = 0;
    seg[k].primer = asignar(v, a, b, 2*k, x, d) + asignar(v, a, b, 2*k + 1, d + 1, y);
    return seg[k].primer;
 
}
int sumar(int a, int b, int k, int x, int y) {
    if (b < x || a > y) return 0;
    if (a <= x && b >= y) {
        return seg[k].primer + (y-x+1)*seg[k].segundo;
    }
    push(k); 
    seg[k].primer += (y-x+1)*seg[k].segundo;
    seg[2*k].segundo += seg[k].segundo, seg[2*k + 1].segundo += seg[k].segundo;
    seg[k].segundo = 0;
    int d = (x+y)/2;
    return sumar(a, b, 2*k, x, d) + sumar(a, b, 2*k + 1, d + 1, y);
}


signed main(){
    cin>>segundo; N = segundo.size();
    suffix();
    crearLCP();
    int k; cin>>k;

    k = N*(N+1)/2 - k + 1; 
    int K = 1<<(int) ceil(log2(N+1));
    int cur = 0;
    for (int i = N-1; i >= 0; i--) {
        actualizar(1, 1, N-sa[i], 1, 0, K-1);
        int prev = (i ? lcp[i-1] : 0);
        int l = prev+1, r = N-sa[i];
        int ans = -1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (cur + sumar(m, N-sa[i], 1, 0, K-1) >= k) {
                ans = m; l = m + 1;
            }
            else r = m - 1;
        }
        if (ans != -1) {
            return cout << segundo.substr(sa[i], ans), 0;
        }
        cur += sumar(prev+1, N-sa[i], 1, 0, K-1);
        asignar(0, prev+1, N-sa[i], 1, 0, K-1);
    }
}