  #include <bits/stdc++.h>
  using namespace std;

  int main() {
    int n;
    int a,b;

    cin>>n;
    cin>>a;
    cin>>b;

    vector<long long> values(n+1);
    set<pair<long long,int>> sumas;
    long long maxsum = INT_MIN;
    for(int i=1;i<=n;i++){
      cin>>values[i];
    }
    for(int i=1;i<=n;i++){
      values[i] += values[i-1];
    }
    for(int i=a;i<=b;i++){
      sumas.insert({values[i],i});

    }

    for(int i=1;i <= n-a+1;i++){
      maxsum = max(maxsum,sumas.rbegin()->first - values[i-1]);
      sumas.erase({values[i+a-1],i+a-1});
      if(i+b <=n){
        sumas.insert({values[i+b],i+b});
      }
    }
    cout<<maxsum<<"\n";
  }