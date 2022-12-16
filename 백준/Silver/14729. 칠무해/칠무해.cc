#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*

*/


int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<double> v(N, 0);
	for(int i = 0; i < N; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < 7; i++){
		cout << fixed;
		cout.precision(3);
		cout << v[i] << "\n";
	}
	
	return 0;
}