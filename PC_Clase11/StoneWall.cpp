// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &H) {
  int fin=0;
  int bloques = 0;
  vector<int> alma;
  for(int i=0;i<H.size();i++){
    if(H[i] > fin){
      fin = H[i];
      bloques++;
      alma.push_back(H[i]);
    }
    else if(H[i]<fin){
      int j = alma.size()-1;
      while(H[i] < alma[j]){
        alma.pop_back();
        j--;
      }
      if(H[i] != alma[alma.size()-1]){
        bloques++;
        alma.push_back(H[i]);
      }
      fin = H[i];
    }
  }
  return bloques;
}