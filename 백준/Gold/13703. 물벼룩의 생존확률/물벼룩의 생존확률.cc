// 13703 물벼룩의 생존확률
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
1 위치, 시간 입력
2 시간 0이 될때까지 sol돌리기, pos > 0인 수 카운트

2 pos = 0 return 0
2 time == 0 && pos > 0 return 

*/
ll dp[1000][1000];

ll sol(int pos, int time){
	ll& ret = dp[pos][time];
	if(ret != -1) return ret;

	if(pos == 0){
		ret = 0;
		return 0;
	}
	if(time == 0 && pos > 0){
		ret = 1;
		return 1;
	}
	ret = sol(pos-1, time-1) + sol(pos+1, time-1);
	
	return ret;
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int k, n; cin >> k >> n;
	for(int i = 0; i < 1000; i++){
		for(int j = 0; j < 1000; j++){
			dp[i][j] = -1;
		}
	}
	ll s = sol(k, n);
	for(int i = 0; i <= 20; i++){
		for(int j = 0; j <= 20; j++){
			//cout << dp[i][j] << " ";
		}
		//cout << "\n";
	}

	cout << s;
	
	return 0;
}