#include <iostream>
using namespace std;

int comp(const void *p, const void *q) {
  int *a = (int *) p;
  int *b = (int *) q;
  return *a - *b;
}

int main() {
  long n, t;
  long a, b, c;
  long p, s, i, t_p;
  long arr[10000];

  cin >> n >> t >> a >> b >> c >> arr[0];

  for (i = 1; i < n; i++)
    arr[i] = (a * arr[i-1] + b) % c + 1;

  qsort(arr, n, sizeof(long), comp);

  p = 0;
  s = 0;
  t_p = 0;
  for (i = 0; i < n; i++) {
    if (t_p + arr[i] <= t) {
      p = (p + arr[i] + t_p) % 1000000007;
      t_p += arr[i];
      s++;
    } else {
      break;
    }
  }

  cout << s << " " << p << endl;
  return 0;
}