// 11052번 카드 구매하기
/*
dp[N]: N개를 갖기 위한 최댓값 update

dp[i-1] + v[1] vs v[i] X
가능한 숫자 조합이 전부 있어야 한다 X
0-i max + i의 값 vs 
N개의 max dp[i] + v[i] vs 

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

const int MV = 1005;

int v[MV];
int dp[MV];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for(int i = 1; i <= N; i++){
		cin >> v[i];
	}

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= i; j++){
			// cout << i-j << " " << j << " " << i << "\n";
			dp[i] = max(dp[i-j] + v[j], dp[i]);
		}
		// cout << dp[i] << " \n";
	}

	cout << dp[N];
	
	return 0;
}