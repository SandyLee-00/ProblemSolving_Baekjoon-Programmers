// 1788번 피보나치 수의 확장
#include<bits/stdc++.h>
using namespace std;
/*
1 수 입력
2 양수 0 음수 출력
3 f0, f1, f-1 일 때 출력, 양수 -> 양수 피보, 음수 -> 음수 피보 실행

3 

*/

int dp[1000005];

int fib(int cur){
	int& ret = dp[cur];
	if(ret != -1) return ret;
	
	if(cur == 0) return 0;
	if(cur == 1) return 1;

	ret = (fib(cur-1) + fib(cur-2)) % 1000000000;
	
	return ret;
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for(int i = 0; i < 1000005; i++){
		dp[i] = -1;
	}

	int n; cin >> n;
	if(n > 0) cout << 1 << "\n";
	else if(n == 0) cout << 0 << "\n";
	else if(n < 0 && n % 2 == 0) cout << -1 << "\n";
	else cout << 1 << "\n";

	long long res;
	if(n >= 0){
		res = fib(n);
	}
	else{
		res = fib(-n);
	}
	cout << res;
	
	return 0;
}