// 14494번 다이나믹이 뭐예요?
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
1 목표 i, j 입력
2 이동 경우 수 리턴하는 함수(curi, curj, n, m)

2 j + 1 / i + 1 / i + 1 , j + 1
ret = (sol(1) + sol(2) + sol(3)) % MOD;å

*/
long long dp[1005][1005];
const int MOD = 1000000007;

ll sol(int n, int m){
	ll& ret = dp[n][m];
	if(ret != -1) return ret;
	
	if(n == 1 && m == 1){
		ret = 1;
		return ret;
	}
	if(n == 2 && m == 2){
		ret = 3;
		return ret;
	}
	if(n == 1){
		ret = 1;
		return ret;
	}
	if(m == 1){
		ret = 1;
		return ret;
	}
	
	ret = ((sol(n - 1, m - 1) + sol(n, m - 1)) % MOD + sol(n - 1, m)) % MOD;

	return ret;
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;

	for(int i = 0; i < 1005; i++){
		for(int j = 0; j < 1005; j++){
			dp[i][j] = -1;
		}
	}

	ll res = sol(n,m);
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			// cout << dp[i][j] << " ";
		}
		// cout << "\n";
	}
	
	cout << res;
	
	return 0;
}