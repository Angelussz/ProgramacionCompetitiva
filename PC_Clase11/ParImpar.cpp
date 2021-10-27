#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int ascending(void const *a, void const *b )
{
    return (*(int*)a - *(int*)b );
}

int descending(void const *a, void const *b )
{
    return (*(int*)b - *(int*)a );
}


int main() {
  int n,i;
  int num,par=0,impar=0;

  cin>>n;
  
  vector<int> arrpar;
  vector<int> arrimp;
  for(i = 0; i < n; i++){
        cin>>num;
        if(num%2 == 0){
            arrpar.push_back(num);
            par++;
        }else{
            arrimp.push_back(num);
            impar++;
        }
    }
  qsort(&arrpar[0], arrpar.size(), sizeof(int), ascending);
  qsort(&arrimp[0], arrimp.size(), sizeof(int), descending);
  // cout<<"resultado"<<endl;
  for(i = 0; i < par; i++){
        cout<<arrpar[i]<<endl;
    }
    for(i = 0; i < impar; i++){
        cout<<arrimp[i]<<endl;
    }
    
    return 0;



} 