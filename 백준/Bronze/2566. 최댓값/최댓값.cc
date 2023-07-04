#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int array[10][10];
  int maxV = INT_MIN;
  int resi = 0;
  int resj = 0;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> array[i][j];
      int tmp = maxV;
      maxV = max(maxV, array[i][j]);
      if (maxV != tmp) {
        resi = i;
        resj = j;
      }
    }
  }

  cout << maxV << "\n" << resi + 1 << " " << resj + 1;

  return 0;
}