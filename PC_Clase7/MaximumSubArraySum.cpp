/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums{-1,3,-2,5,3,-5,2,2};
    int maximo,maximo_global;
    maximo = maximo_global=nums[0];

    for(int i=1;i<nums.size();i++){
      maximo = max(nums[i], maximo+nums[i]);
      if(maximo > maximo_global){
        maximo_global = maximo;
      }
    }
    cout<<maximo_global<<"\n"; 


    return 0;
}