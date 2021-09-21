
#include <bits/stdc++.h>
using namespace std;
int contador(vector<int> vec,int k){ //Funcion para entregar numeros divisibles de K
    int cont = 0;
    for(int i=0;i<vec.size();i++){ //Primer for: de cuanto en cuento va contar
        // cout<<"hhla\n";
        for(int j=i;j<vec.size();j++){//Segundo for: recorrer el arreglo
            int sum = 0;
            
            for(int k=0;k<=i;k++){// Tercer for: sumar dependiendo del primer for
                sum = sum+vec[j-k];
            }
            // cout<<sum<<endl;
            if(sum % k == 0){
                cont++;
            }
        }
    }
    return cont;
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> num;
    int n,k,val;
    cin>>n;
    cin>>k;
    for(int i=0;i<n;i++){
        cin>>val;
        num.push_back(val);
    }
    
    cout<<"valor: "<<contador(num,k);
    
    
    // for(int i=0;i<num.size();i++){
    //     cout<<num[i]<<" ";
    // }
    // return 0;
}

