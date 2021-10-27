#include <bits/stdc++.h>
using namespace std;

int ascending(void const *a, void const *b )
{
    return (*(int*)a - *(int*)b );
}

int main() {
  int NC;
  int N;
  int num;
  cin>>NC;
  
  while(NC--){
    cin>>N;
    vector<int> nums;
    for(int i=0;i<N;i++){
      cin>>num;
      nums.push_back(num);
    }
    qsort(&nums[0], nums.size(), sizeof(int), ascending);
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
} 