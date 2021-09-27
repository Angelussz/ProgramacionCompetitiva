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
    vector<int> nums{3,4,7,2,-3,1,4,2};
    int n = nums.size();
    int k = 7;
    if(n==0){
        return 0;
    }
    
    unordered_map<int,int> mymap;
    int currSUM=0;
    int i=0;
    int count = 0;
    
    while(i<n){
        currSUM +=nums[i];
        if(mymap.find(currSUM-k)!=mymap.end()){
            count+=mymap[currSUM-k];
            
        }
        mymap[currSUM] +=1;
        i++;
    }
    
    printf("%d",count);
    
}