// 11726번 2×n 타일링
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <deque>
using namespace std;

int dp[1001];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	int moduler = 10007;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for(int i = 4; i <= 1000; i++){
		dp[i] = (dp[i-1] + dp[i - 2]) % moduler;
		//cout << dp[i] << "\n";
	}

	cout << dp[n];
	
	return 0;
}