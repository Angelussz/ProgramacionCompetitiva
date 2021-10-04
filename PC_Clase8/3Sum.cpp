/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>nums {-1,0,1,2,-1,-4};
    int n = nums.size();
    if(n<3){
        cout<<"[]";
    }
    else{
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n-2;i++){
            if(i==0 || nums[i] != num[i-1]){
                int j = i+1,k=n-1;
                
                while(j<k){
                    int sum = nums[i]+nums[j]+nums[k];
                    if(sum==0){
                        result.push.back({nums[i],nums[j],nums[k]});
                        while(j<k && nums[j] == nums[j+1]){
                            j++;
                        }
                        while(j<k && nums[k] == nums[k-1]){
                            k--;
                        }
                        j++;k--;
                    }
                    else if(sum >0){
                        k--
                    }
                    else{
                        j++;
                    }
                    
                }
            }
        }
        }
    }
    

    return 0;
}

