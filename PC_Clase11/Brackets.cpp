#include <bits/stdc++.h>
using namespace std;

int solution(string &S){
  if(S.empty()){
    return 1;
  }
  vector<int> pila;
  int val=0;

  for(int i=0;i<S.size();i++){
    if(S[i]=='['){
      val=1;
    }
    if(S[i]==']'){
      val=1;
    }
    if(S[i]=='('){
      val=2;
    }
    if(S[i]==')'){
      val=2;
    }
    if(S[i]=='{'){
      val=3;
    }
    if(S[i]=='}'){
      val=3;
    }

    if(i==0 && val<0){
      return 0;
    }

    if(val<0 && val!=-pila.back()){
      return 0;
    }
    else if(val<0){
      pila.pop_back();
    }
    else{
      pila.push_back(val);
    }
  }
}