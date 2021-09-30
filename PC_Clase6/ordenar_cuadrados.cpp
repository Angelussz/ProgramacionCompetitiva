/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums{-4,-1,0,3,10};
    vector<int> pos(nums.size(), 0);;
    int target = 18;
    
    int punt1 = 0;
    int punt2 = nums.size()-1;
    int i = nums.size()-1;
    while(i>=0){
        if(nums[punt1]*nums[punt1] > nums[punt2]*nums[punt2]){
            pos[i]=nums[punt1]*nums[punt1];
            i--;punt1++;
        }
        else{
            pos[i]=nums[punt2]*nums[punt2];
            i--;punt2--;
        }
        
    }
    for(int b = 0;b<pos.size();b++){
        cout<<pos[b]<<" "<<endl;
    }
    return 0;
}