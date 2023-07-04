#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int T;
	cin >> T;
	while(T--){
		int exchange;
		cin >> exchange;
		int Q = exchange / 25;
		exchange -= 25 * Q;
		int D = exchange % 25 / 10;
		exchange -= 10 * D;
		int N = exchange / 5;
		exchange -= 5 * N;
		int P = exchange;
		cout << Q << " " << D << " " << N << " " << P << "\n";
	}
  
  return 0;
}