#include <bits/stdc++.h>

using namespace std;

int exam2(int n){
    return n & (-n);
}

int arrnum[500001];

int examinar(int a){
    int soma = 0;
    while(a > 0){
        soma += arrnum[a];
        a -= exam2(a);
    }
    return soma;
}

void actualizar(int a, int v){
    while(a < 500001){
        arrnum[a] += v;
        a += exam2(a);
    }
}

int main(){
    int n;
    cin>>n;
    memset(arrnum, 0, sizeof arrnum);
    int num;
    for(int i = 1; i <= n; i++){
        cin>>num;
        printf("%d%s", (num - examinar(num)), (i == n ? "\n" : " "));
        actualizar(num, 1);
    }

    return 0;
}