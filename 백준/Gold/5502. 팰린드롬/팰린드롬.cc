// 5502번 팰린드롬
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
1 문자열 입력
2 문자 길이 - 최장 공통 문자열 구하기 원본, 뒤집은 것
3 결과 출력

2 LCS 연속한 것만 구하기 다르면 

*/
string str;
string strR;
int dp[5005][5005];
int maxRes = 0;

int sol(int strIdx, int strRIdx){
	if(strIdx == -1 || strRIdx == -1) return 0;
	int& ret = dp[strIdx][strRIdx];
	if(ret != -1) return ret;
	
	if(str[strIdx] == strR[strRIdx]){
		ret = sol(strIdx-1, strRIdx-1) + 1;
	}
	if(str[strIdx] != strR[strRIdx]){
		ret = max(sol(strIdx, strRIdx-1), sol(strIdx-1, strRIdx));
	}
	
	maxRes = max(maxRes, ret);

	return ret;
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	cin >> str;
	for(int i = 0; i < str.size(); i++){
		strR += str[N-i-1];
	}
	for(int i = 0; i < 5005; i++){
		for(int j = 0; j < 5005; j++){
			dp[i][j] = -1;
		}
	}
	sol(N-1, N-1);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			//cout << dp[i][j] << " ";
		}
		//cout << "\n";
	}
	
	int res = N - maxRes;
	cout << res;
	
	return 0;
}