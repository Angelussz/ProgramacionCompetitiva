#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin>>a>>b;

  int cuadrados[a+1][b+1];
  for(int alt = 1; alt <= a; alt++){
    for(int anch = 1;anch <= b; anch++){
      if (anch == alt){
        cuadrados[alt][anch] = 0;
      }
      else{
        int resp = INT_MAX;
        for(int i=1;i<anch;i++){
          resp = min(resp,1+cuadrados[alt][anch-i]+cuadrados[alt][i]);
        }
        for(int i=1;i<alt;i++){
          resp = min(resp,1+cuadrados[alt-i][anch]+cuadrados[i][anch]);
        }
        cuadrados[alt][anch] = resp;
      }
    }
  }
  cout<<cuadrados[a][b];
} 