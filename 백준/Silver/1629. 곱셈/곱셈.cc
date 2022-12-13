// 1629번 곱셈
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*

*/

ll sol(ll a, ll b, ll c){
	ll ret;
	
	if(b == 1){
		ret = a % c;
		return ret;
	}
	
	if(b % 2 == 0){
		ret = sol(a, b/2, c) * sol(a, b/2, c);
	}
	else if(b % 2 == 1){
		ret = sol(a, b/2, c) * sol(a, b/2, c) %c * a;
	}
	return ret % c;
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll A, B, C; cin >> A >> B >> C;
	ll res = 1;

	res = sol(A, B, C) % C;
	
	cout << res;
	
	return 0;
}