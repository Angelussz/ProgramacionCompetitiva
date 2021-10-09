#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;

  stack<pair<int,int>> minimo;
  vector<int> nums(n);
  for(int i =0;i<nums.size();i++){
    cin>>nums[i];
  }
  for(int i = 0;i<n;i++){
    while(!minimo.empty() && minimo.top().first >= nums[i]){
      minimo.pop();
    }
    if(!minimo.empty()){
      cout<<minimo.top().second<<" ";
    }
    else{
      cout<<0<<" ";
    }
    minimo.push({nums[i],i+1});
  }
}