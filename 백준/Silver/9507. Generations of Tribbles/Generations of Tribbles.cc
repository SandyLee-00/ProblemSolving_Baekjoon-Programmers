// 9507번 Generations of Tribbles
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*

*/
ll dp[100];

ll koong(ll n){
	ll& ret = dp[n];
	if(ret != 0) return ret;
	
	if(n < 2)
		return 1;
	if(n == 2)
		return 2;
	if(n == 3)
		return 4;
	else{
		ret = koong(n-1) + koong(n-2) + koong(n-3) + koong(n-4);
	}
	return ret;
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	
	while(t--){
		int n; cin >> n;
		ll res = koong(n);
		cout << res << "\n";
	}
	
	return 0;
}