/******************************************************************************

Maximum sum of any contiguous subarray of size k

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums{2,3,4,1,5};
    int k=3;
    int inic = 0;
    int sum = 0;
    int maxim = INT_MIN;
    
    
    
    for(int fin=0;fin < nums.size();fin++){
        if(fin<k){
            sum = sum+nums[fin];
            maxim = sum;
        }
        else{
            sum = sum-nums[inic];
            sum = sum+nums[fin];
            // cout<<sum<<"\n";
            maxim = max(maxim,sum);
            inic++;
        }
    }
    
    if (maxim == 0){
        cout<<0<<"\n";
    }
    else{
        cout<<maxim<<"\n";
    }

    return 0;
}