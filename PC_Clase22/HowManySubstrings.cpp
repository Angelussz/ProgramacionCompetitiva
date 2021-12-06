#include <bits/stdc++.h>
using namespace std;

#define MN 200011

struct state {
  int len, link;
  long long num_prof;
  map<int, int> sig;
};


state auxarr[MN << 1];
int sz, last;
long long paths;

void comienzo() {
  sz = 1;
  last = 0;
  auxarr[0].len = 0;
  auxarr[0].link = -1;
  auxarr[0].sig.clear();
  auxarr[0].num_prof = 1;
  paths = 0;
}

void extension(int c) {
  int cur = sz++;
  auxarr[cur].len = auxarr[last].len + 1;
  auxarr[cur].sig.clear();
  auxarr[cur].num_prof = 0;
  int p;
  for (p = last; p != -1 && !auxarr[p].sig.count(c); p = auxarr[p].link) {
    auxarr[p].sig[c] = cur;
    auxarr[cur].num_prof += auxarr[p].num_prof;
    paths += auxarr[p].num_prof;
  }

  if (p == -1) {
    auxarr[cur].link = 0;
  } else {
    int q = auxarr[p].sig[c];
    if (auxarr[p].len + 1 == auxarr[q].len) {
      auxarr[cur].link = q;
    } else {
      int clone = sz++;
      auxarr[clone].len = auxarr[p].len + 1;
      auxarr[clone].sig = auxarr[q].sig;
      auxarr[clone].num_prof = 0;
      auxarr[clone].link = auxarr[q].link;
      for (; p!= -1 && auxarr[p].sig[c] == q; p = auxarr[p].link) {
        auxarr[p].sig[c] = clone;
        auxarr[q].num_prof -= auxarr[p].num_prof;
        auxarr[clone].num_prof += auxarr[p].num_prof;
      }
      auxarr[q].link = auxarr[cur].link = clone;
    }
  }
  last = cur;
}


int main() {
  
  string line;
  while (cin >> line) {
    comienzo();
    for (size_t i = 0; i < line.size(); i++) 
    {
        if (line[i] == '?') cout << paths << "\n";
        else extension(line[i]);
    }
  }
  return 0;
}


