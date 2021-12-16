#include<bits/stdc++.h>

using namespace std;

int main() {
  int numBus, i, j;
  cin >> numBus;
  int bus[numBus];

  for (i = 0; i < numBus; i++) {
    cin >> bus[i];
  }
  for (i = 0; i < numBus; i++) {
    int smallest = i;
    int swap;
    
    for (j = i + 1; j < numBus; j++) {
      if (bus[j] < bus[smallest]) {
        smallest = j;
      }
    }

    swap = bus[i];
    bus[i] = bus[smallest];
    bus[smallest] = swap;
  }

  int rango = 0;
  cout << bus[0];
  for (i = 1; i < numBus; i++) {
    if (bus[i - 1] + 1 == bus[i]) {
      rango++;
    } else {
      if (rango > 1) {
        cout << "-" << bus[i - 1];
      } else if (rango == 1) {
        cout << " " << bus[i - 1];
      }
      rango = 0;
      cout << " " << bus[i];
    }
  }
  if (rango > 1) {
    cout << "-" << bus[i - 1];
  } else if (rango == 1) {
    cout << " " << bus[i - 1];
  }
}