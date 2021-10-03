/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums{2,3,4,1,5};
    int k = 3;
    
    deque<int> dq;
    vector<int> ans;
    
    for(int i=0;i<nums.size();i++){
        if(!dq.empty() && dq.front() == i-k){
            dq.pop_front();
        }
        
        while(!dq.empty() && nums[dq.back]<nums[i]){
            dq.pop_back();
        }
        
        dq.push_back(i);
        if(i>=k-1){
            ans.push_back(nums[dq.front()]);
        }
    }
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<< " ";
    }

    return 0;
}
