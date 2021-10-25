#include <bits/stdc++.h>
using namespace std;

// EL CODIGO ES EL MISMOS QUE EL DE BRAKETS SOLO SIN CONSIDERAR LLAVES NI CORCHETES

int solution(string &S){
  if(S.empty()){
    return 1;
  }
  vector<int> V;
  int t=0;

  for(int i=0;i<S.size();i++){
    
    if(S[i]=='('){
      t=+2;
    }
    if(S[i]==')'){
      t=-2;
    }
    

    if(i==0 && t<0){
      return 0;
    }

    if(t<0 && t!=-V.back()){
      return 0;
    }
    else if(t<0){
      V.pop_back();
    }
    else{
      V.push_back(t);
    }
  }

  if(V.empty()){
    return 1;
  }
  else{
    return 0;
  }
  return 0;  
}