/******************************************************************************

Tamaño minimo minimo de un subarray igual o mayor a K;

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums{7,2,1,1,6,5};
    int k=11;
    int inic = 0;
    int sum = 0;
    int tamin = INT_MAX;
    
    for(int fin = 0;fin < nums.size();fin++){
        sum = sum + nums[fin];
        
        while(sum >= k && inic<=fin){
            tamin = min(tamin,(fin-inic)+1);
            // cout<<tamin<<endl;
            sum = sum - nums[inic++];
        }
    }
    
    if (tamin==INT_MAX){
        cout<<0<<"\n";
    }
    else{
        cout<<tamin<<"\n";
    }

    return 0;
}


