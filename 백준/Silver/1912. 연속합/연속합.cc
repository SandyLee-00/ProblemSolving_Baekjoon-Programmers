// 1912번 연속합
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<int> nums;
	for(int i = 0; i < n; i++){
		int nums_e; cin >> nums_e;
		nums.push_back(nums_e);
	}
	vector<int> dp(n);
	dp[0] = nums[0];
	
	for(int i = 1; i < n; i++){
		// cout << dp[i - 1] << "\n";
		dp[i] = max(dp[i - 1] + nums[i] , nums[i]);
	}
	sort(dp.begin(), dp.end(), greater<>());
	
	cout << dp[0];
	
	return 0;
}