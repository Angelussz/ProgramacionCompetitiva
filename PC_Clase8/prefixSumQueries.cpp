/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int maxPrefix(vector<int> values, int inic, int fin){
    int start = inic-1;
    int end  = fin-1;
    int max_current,max_global;
    
    max_current=max_global=values[start];
    
    for(int i=start+1;i<fin;i++){
        max_current = max(values[i],max_current+values[i]);
        if(max_current>max_global){
            max_global = max_current;
        }
    }
    return max_global;
    
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=8,k=4;
    vector<int> values{1,2,-1,3,1,-5,1,4};
    
    int tipo,a,b;
    
    for(int i=0;i<k;i++){
        cin>>tipo;
        cin>>a;
        cin>>b;
        if(tipo == 1){
            values[a-1] = b;
        }
        else if(tipo == 2){
            cout<<maxPrefix(values,a,b)<<"\n";
        }
        else{
            cout<<"NO CONSULTA\n";
        }
    }
  
  
}


