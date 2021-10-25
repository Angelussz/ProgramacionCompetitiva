// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
int solution(vector<int> &A, vector<int> &B) {
    vector<int> abajo;
  int como=0;

  for(int i=0;i<B.size();i++){
    if(B[i] == 1){
      abajo.push_back(A[i]);
    }
    else{
      while(!abajo.empty()){
        if(abajo.back() > A[i]){
          como++;
          break;
        }
        else if(abajo.back() < A[i]){
          abajo.pop_back();
          como++;

        }
      }
    }
  }
  return A.size()-como;
}