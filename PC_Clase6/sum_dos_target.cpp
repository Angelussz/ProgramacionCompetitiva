/******************************************************************************

Given an array of integers that is already sorted in ascending order,find two numbers
such that add up to a specific target number

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums{2,7,11,15};
    vector<int> pos;
    int target = 18;
    
    int punt1 = 0;
    int punt2 = nums.size()-1;
    
    while(punt1!=punt2){
        if(nums[punt1]+nums[punt2] == target){
            pos.push_back(punt1);
            pos.push_back(punt2);
            break;
        }
        else if(nums[punt1]+nums[punt2] > target){
            punt2--;
        }
        else if (nums[punt1]+nums[punt2] < target){
            punt1++;
        }
    }
    if(pos.empty()){
        cout<<"no existe\n";
    }
    else{
        cout<<pos[0]+1<<" "<<pos[1]+1<<"\n";
    }
    return 0;
}