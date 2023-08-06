// 17626번 Four Squares
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <climits>
using namespace std;

/*

*/


int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; 
	cin >> n;

	const int RANGE = 230;
	vector<int>dp(60001, INT_MAX);

	dp[0] = 0;
	
	for(int i = 1; i < 50001; i++){
		dp[i] = dp[i-1] + 1;
		for(int j = 1; j * j <= i; j++){
			dp[i] = min(dp[i], dp[i - j*j] + 1);
		}
		// cout << dp[i] << "\n";
	}

	cout << dp[n];

	return 0;
}