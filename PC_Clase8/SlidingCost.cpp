/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
typedef long long ll;

int main () {
  int n=8,k=3;
//   cin>>n>>k;
  
  set<pair<int,int>> leftSet;
  set<pair<int,int>> rightSet;
  vector<int> values{2,4,3,5,8,1,2,1};
//   vector<int> values(n) ;
//   for(int i = 0;i<n;i++){
//       cin>>values[i];
//   }
  
  if(k==1){
      for(int i = 0;i<n;i++){
          cout<<0<<" ";
      }
      return 0;
  }
  if(k==2){
      for(int i=0;i<n;i++){
          cout<<abs(values[i-1]-values[i])<<" ";
          return 0;
      }
  }
  
  vector<pair<int,int>> st;
  for(int i = 0;i<k;i++){
      st.push_back({values[i],i});
  }
  sort(st.begin(),st.end());
  
  ll leftSetSum = 0;
  ll rightSetSum = 0;
  
  for(int i = 0;i<k/2 + (k%2);i++){
      leftSet.insert(st[i]);
      leftSetSum += st[i].first;
  }
  
  for(int i=k/2 +(k%2);i<k;i++){
      rightSet.insert(st[i]);
      rightSetSum += st[i].first;
  }
  ll median = leftSet.rbegin()->first;
  cout<<median*leftSet.size() - leftSetSum + rightSetSum - median* rightSet.size()<<" ";
  
  for(int j=1;j<n-k+1;j++){
      if(leftSet.count({values[j-1],j-1})){
          leftSetSum -= values[j-1];
          leftSet.erase({values[j-1],j-1});
      }
      else{
          rightSetSum -= values[j-1];
          rightSet.erase({values[j-1],j-1});
      }
      if(*(leftSet.rbegin()) < make_pair(values[k-1+j],k-1+j)){
          rightSetSum += values[k-1+j];
          rightSet.insert({values[k-1+j],k-1+j});
      }
      else{
          leftSetSum += values[k-1+j];
          leftSet.insert({values[k-1+j],k-1+j});
      }
      while(leftSet.size() < k/2 +(k%2)){
          pair<int,int> z = (*rightSet.begin());
          leftSet.insert(z);
          leftSetSum += z.first;
          rightSet.erase(z);
          rightSetSum -= z.first;
          
        //   cout<<"hola\n";
      }
      while(leftSet.size() > k/2 +(k%2)){
          pair<int,int> z = (*leftSet.rbegin());
          leftSet.erase(z);
          leftSetSum -= z.first;
          rightSet.insert(z);
          rightSetSum += z.first;
        //   cout<<"hola2\n";
      }
      median = leftSet.rbegin() -> first;
      cout<<median*leftSet.size() - leftSetSum + rightSetSum - median* rightSet.size()<<" ";
  }
}

