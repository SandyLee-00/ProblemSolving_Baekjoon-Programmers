// 12865번 평범한 배낭
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int w[101];
int v[101];
int dp[100001];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N; //물건 수
	int K; cin >> K; // 최대 무게
	
	for(int i = 1; i <= N; i++){
		cin >> w[i];
		cin >> v[i];
	}

	for(int i = 1; i <= N; i++){
		for(int j = K; j >= 1; j--){
			// cout << "j :" << j << " "<< dp[j] << " -> ";
			if(j-w[i] >= 0){
				dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
				// cout << dp[j] << " ";
			}
			// cout << "\n";
		}
		// cout << "\n";
	}
	cout << dp[K];
	
	return 0;
}