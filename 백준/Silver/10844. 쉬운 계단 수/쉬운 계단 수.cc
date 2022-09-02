// 10844번 쉬운 계단 수
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
using namespace std;

int moduler = 1000000000;
int dp[101][10];
// dp[i][j] i길이 j로 끝남 

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for(int i = 1; i <= 9; i++){
		dp[1][i] = 1;
	}

	for(int i = 2; i <= N; i++){
		for(int j = 1; j <= 8; j++){
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % moduler ;
		}
		dp[i][0] = dp[i-1][1];
		dp[i][9] = dp[i-1][8];
	}

	int res = 0;
	for(int i = 0; i <= 9; i++){
		res += dp[N][i];
		res %= moduler;
	}

	cout << res;
	
	return 0;
}