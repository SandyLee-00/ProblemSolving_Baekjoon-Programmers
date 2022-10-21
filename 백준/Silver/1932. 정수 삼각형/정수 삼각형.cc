// 1932번 정수 삼각형
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

/*
각 층의 원소 값에서 선택 가능한 것 중 최대 고르기 왼쪽 오른쪽
dp[i][j] = max(dp[i-1][j], dp[i-1][j+1]) + cost[i][j] // i층의 j원소
*/

int dp[501][501];
int cost[501][501];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= i; j++){
			int a; cin >> a;
			cost[i][j] = a;
		}
	}
	dp[0][0] = cost[0][0];
	
	for(int i = 1; i < N; i++){
		for(int j = 0; j <= i; j++){
			dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + cost[i][j];
			//cout << dp[i][j] << " ";
		}
		//cout << "\n";
	}
	int res = 0;
	for(int i = 0; i < N; i++){
		//cout << dp[N-1][i] << " ";
		res = max(res, dp[N-1][i]);
	}
	cout << res;
	
	return 0;
}