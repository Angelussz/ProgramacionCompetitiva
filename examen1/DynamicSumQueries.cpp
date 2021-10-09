#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int q;
    int tipo,a,b;
    cin>>n;
    cin>>q;
    vector<int> nums(n); 
    vector<int> sumas(n+1);
    
    for(int i=0;i<n;i++){
      cin>>nums[i];
      // cout<<i+1<<endl;
    }
    sumas[0]=0;
    for(int i=1;i<n+1;i++){
      sumas[i]=nums[i-1]+sumas[i-1];
    }

    int menos =0;
    for(int i=0;i<q;i++){
      cin>>tipo>>a>>b;
      if(tipo==1){
        menos = menos+(nums[a-1]-b);

         
        // nums[a-1] = b;
        // for(int i=a;i<n+1;i++){
        //   sumas[i] = nums[i-1]+sumas[i-1];
           
        // }
        
        // cout<<"cambiante: "<<nums[0]<<"posicion "<<a-1<<endl;
        // for(int i=0;i<n+1;i++){
        //   cout<<sumas[i]<<" ";
        // }
        
      }
      else{
        cout<<sumas[b]-sumas[a-1]-menos<<endl;  
        // cout<<"cambio"<<nums[0]<<endl;
    }

    // for(int i=0;i<n;i++){
    //   cout<<nums[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<n+1;i++){
    //   cout<<sumas[i]<<" ";
    // }

  
}
}


