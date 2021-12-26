#include <bits/stdc++.h>
using namespace std;

const int maxim = 100005;
int rank_c[maxim], wb[maxim], wv[maxim], wss[maxim];
int n;

bool comparar(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(char *r, int *sa, int n, int m)
{
    int i, j, p, *x = rank_c, *y = wb, *t;
    for (i = 0; i<m; i++) wss[i] = 0;
    for (i = 0; i<n; i++) wss[x[i] = r[i]]++;
    for (i = 1; i<m; i++) wss[i] += wss[i - 1];
    for (i = n - 1; i >= 0; i--)sa[--wss[x[i]]] = i;
    for (j = 1, p = 1; p<n; j *= 2, m = p)
    {
        for (p = 0, i = n - j; i<n; i++) y[p++] = i;
        for (i = 0; i<n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
        for (i = 0; i<n; i++) wv[i] = x[y[i]];
        for (i = 0; i<m; i++) wss[i] = 0;
        for (i = 0; i<n; i++) wss[wv[i]]++;
        for (i = 1; i<m; i++) wss[i] += wss[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--wss[wv[i]]] = y[i];
        for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i<n; i++)
            x[sa[i]] = comparar(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
    return;
}

int main()
{
    char s[maxim];
    int r[maxim], sa[maxim], i,l;
    while (fgets(s,maxim,stdin))
    {
        l = strlen(s);
        da(s, sa, l, 130);
        int num;
        cin >> num;
        int flag = 0;
        for (i = 0; i < num; i++)   // sa[i] : 排在第i个的是谁 
        {
            int target;
            scanf("%d", &target);
            if (flag)
                printf(" %d", sa[target + 1]);
            else
            {
                flag = 1;
                printf("%d", sa[target + 1]);
            }
        }
        printf("\n");
        getchar();
    }
    return 0;
}