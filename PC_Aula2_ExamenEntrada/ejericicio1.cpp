#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
    string p1;
    string p2;
    getline(cin, p1);
    getline(cin, p2);
    for (int i=0;i<p1.length();i++){
      if(p1[i] == ' '){
        p1.erase(i,1);
        i--;
        continue;
      }
      
      for(int j=0;j<p2.length();j++){
        if(p2[j] == ' '){
          p2.erase(j,1);
          j--;
          continue;
        }
        if(p1[i] == p2[j]){
          p2.erase(j,1);
          break;
        }
      }
    }
    if(p2.empty()){
      cout<<"Las palabras son anagramas"<<endl;
    }
    else{
      cout<<"No son anagramas"<<endl;
    }
    return 0;
}