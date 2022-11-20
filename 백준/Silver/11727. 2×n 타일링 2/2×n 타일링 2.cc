// 11727번 2×n 타일링 2
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	
	int dp[1001];
	dp[1] = 1; // |
	dp[2] = 3; // || = ㅁ
	int moduler = 10007;

	for(int i = 3; i <= 1000; i++){
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % moduler;
		// cout << dp[i] << "\n";
	}
	cout << dp[N];
	
	return 0;
}