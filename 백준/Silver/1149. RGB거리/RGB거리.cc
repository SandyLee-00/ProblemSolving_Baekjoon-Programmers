// 1149번 RGB거리
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
using namespace std;

/*
0 빨강 1 초록 2 파랑
N이 빨강 선택할 경우 -> min(N-1에서 파랑, N-1에서 초록)

*/

const int MAX = 1001;
int cost[MAX][3];
int sum[MAX][3];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for(int i = 0; i < N; i++){
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	sum[0][0] = cost[0][0];
	sum[0][1] = cost[0][1];
	sum[0][2] = cost[0][2];
	
	for(int i = 1; i < N; i++){
		
		sum[i][0] = min(sum[i-1][1], sum[i-1][2]) + cost[i][0];
		sum[i][1] = min(sum[i-1][0], sum[i-1][2]) + cost[i][1];
		sum[i][2] = min(sum[i-1][1], sum[i-1][0]) + cost[i][2];

		// cout << i << "집" << sum[i][0] << " " << sum[i][1] << " " << sum[i][2] << " \n";
	}
	int res = min(sum[N-1][0], sum[N-1][1]);
	res = min(res, sum[N-1][2]);
	cout << res;
	
	return 0;
}