#include<bits/stdc++.h>

using namespace std;

int main () {
  int bajoCero = 0, numtemps, i;
  cin >> numtemps;
  for (i = 0; i < numtemps; i++) {
    long temperature;
    cin >> temperature;
    if (temperature < 0) {
      bajoCero++;
    }
  }
  cout << bajoCero;
}