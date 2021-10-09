#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string &S, vector<int> &P,vector<int> &Q){
  vector<int> R;
  vector<int> A (S.size(),0);
  vector<int> C (S.size(),0);
  vector<int> G (S.size(),0);
  vector<int> T (S.size(),0);

  int a=0,c=0,g=0,t=0;
  for(int i=0;i<S.size();i++){
    if(S[i] == 'A'){
      a++;
    }
    else if (S[i] == 'C'){
      c++;
    }
    else if (S[i] == 'G'){
      g++;
    }
    else if(S[i] == 'T'){
      t++;
    }
    A[i] = a;
    C[i] = c;
    G[i] = g;
    T[i] = t;
  }

  for(int i=0;i<P.size();i++){
    if(P[i]==Q[i]){
      if(S[P[i]] == 'A'){
        R.push_back(1);
      }
      else if(S[P[i]] == 'C'){
        R.push_back(2);
      }
      else if(S[P[i]] == 'G'){
        R.push_back(3);
      }
      else if(S[P[i]] == 'T'){
        R.push_back(4);
      }
    }
    else if (A[P[i]] < A[Q[i]] || S[P[i]] == 'A'){
      R.push_back(1);
    }
    else if (C[P[i]] < C[Q[i]] || S[P[i]] == 'C'){
      R.push_back(2);
    }
    else if (G[P[i]] < G[Q[i]] || S[P[i]] == 'G'){
      R.push_back(3);
    }
    else if (T[P[i]] < T[Q[i]] || S[P[i]] == 'T'){
      R.push_back(4);
    }
  }

  
  
  return R;
 }

int main() {
  string S = "CAGCCTA";
  vector<int> P{2,5,0};
  vector<int> Q{4,5,6};
  vector<int> sol = solution(S,P,Q);
  for(int i=0;i<sol.size();i++){
    cout<<sol[i]<<" ";
  }
  return 0;
}