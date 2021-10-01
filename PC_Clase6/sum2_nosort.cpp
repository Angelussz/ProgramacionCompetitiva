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
    // vector<int> nums{-4,-1,0,3,10};
    vector<int> nums;
    int n,x;
    cin>>n>>x;
    map<int,int> position;
    // position[3] = 3;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        if(position.count(x-value)){
            cout<<position[x-value]<<" "<<i+1<<endl;
            return 0;
        }
        position[value]=i+1;
    }
    cout<<"IMPOSIBLE";
    return 0;
}
