#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,q,value;
    int tipo,a,b;
    char letra;
    cin >> n >>q;
  

    vector<char> palabra(n);

    for (size_t i = 0; i < n; i++)
    {
        cin>>palabra[i];
    }
    
    
    int qline;
    
    for(int i = 0;i<q;i++){
      cin>>tipo;
      
      if(tipo == 1){
        cin>>a;
        cin>>letra;
        palabra[a-1] = letra;
        
      }
      else{
        cin>>a;
        cin>>b;
        bool rpta=true;
        a--;
        b--;
        while(a<=b){
          rpta=true;

          if(palabra[a] == palabra[b]){
            a++;
            b--;
          }
          else{
            rpta= false;
            break;
          }
        }
        if(rpta){
          cout<<"YES\n";
        }
        else{
          cout<<"NO\n";
        }
      }
    }

    return 0;
}