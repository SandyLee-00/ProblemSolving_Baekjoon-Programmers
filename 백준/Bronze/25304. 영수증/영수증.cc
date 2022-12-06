//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*

*/

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll X; cin >> X;
	int N; cin >> N;
	for(int i = 0; i < N; i++){
		int a, b; cin >> a >> b;
		X -= a * b;
	}
	if(X == 0)
		cout << "Yes";
	else
		cout << "No";
	
	return 0;
}