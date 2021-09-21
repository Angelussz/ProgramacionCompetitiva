#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int a,num;
  cin>>a;
  vector<int> nums;
  for(int i=0;i<a;i++){
    cin>>num;
    
    nums.push_back(num);
  }

  sort(nums.begin(),nums.begin()+nums.size());
  
  cout<<nums[nums.size()-1]+nums[nums.size()-2];

}