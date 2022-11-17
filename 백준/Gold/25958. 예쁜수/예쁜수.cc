// 25958번 예쁜수
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
1 예쁜 수 구하기 1~ 6000
2 M에서 예쁜 수 목록에서 경우의 수 추가하기

1 v에 넣기
1 각 자리의 수 합 구하기, 약수인지 체크

2 

*/
vector<int> vPreNum;
void get_PreNum(){
	for(int i = 1; i < 6000; i++){
		int tmp = 0;
		int num = i;
		while(1){
			tmp += num % 10;
			num = num / 10;
			if(num == 0) break;
		}
		if(i % tmp == 0){
			vPreNum.push_back(i);
			// cout << i << " ";
		}
			
	}
}
ll dp[1000][6000];
ll sol(int cur, int m, int k){
	ll& ret = dp[cur][m];

	if(ret != 0) return ret;
	
	if(m == 0){
		return 1;
	}
	if(vPreNum[cur] > m){
		return 0;
	}
	ret = (sol(cur, m - vPreNum[cur], k) + sol(cur + 1, m, k)) % k;

	return ret;
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int M; cin >> M;
	int K; cin >> K;
	
	get_PreNum();
	ll res = sol(0, M, K);
	cout << res;
	
	return 0;
}