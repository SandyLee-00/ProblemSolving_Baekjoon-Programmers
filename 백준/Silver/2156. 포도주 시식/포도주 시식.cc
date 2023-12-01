// 포도주 시식
/*
v x o o
? v x o

? ? v x

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <set>
#include <sstream>
using namespace std;

int v[10005];
int dp[10005];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	dp[0] = v[0];
	dp[1] = dp[0] + v[1];
	dp[2] = max(dp[0] + v[2], v[1] + v[2]);
	dp[2] = max(dp[2], dp[1]);

	for(int i = 3; i < n; i++){
		dp[i] = max(dp[i-2], dp[i-3] + v[i-1]) + v[i];
		dp[i] = max(dp[i], dp[i-1]);
		
		// cout << dp[i] << " ";
	}

	cout << dp[n-1] ;
	
	return 0;
}