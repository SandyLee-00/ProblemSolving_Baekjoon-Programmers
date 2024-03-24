// 10942번 팰린드롬?
/*
1개는 전부 p
2개 동일 전부 p
a~b에서 a-1 b-1 p이고 a == b -> p
a~b 홀수개 짝수개 처리...?
- 체크 두번 돌려서 안 된 것도 다시 체크 해놓기
- 위에 방식 틀렸다 가운데부터 쭉 만들어지면...? 
- 그냥 N번 돌리기...? 
- 시간초과...
- 만들어지는 순서가 거꾸로 해야 다 한번 만들어진다 
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int dp[2005][2005];

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> v;
	v.push_back(0);
	
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}

	// 1개는 전부 p
	for(int i = 1; i <= N; i++){
		dp[i][i] = 1;
	}

	// 2개 동일 전부 p
	for(int i = 1; i <= N; i++){
		if(v[i-1] == v[i]){
			dp[i-1][i] = 1;
		}
	}

	// a~b에서 a+1 b-1 p이고 a == b -> p
		for(int i = N; i >= 1; i--){
			for(int j = 1; j <= N; j++){
				if(dp[i+1][j-1] == 1 && v[i] == v[j]){
					dp[i][j] = 1;
				}
			}
		}

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			// cout << dp[i][j] << " "; 
		}
		// cout << "\n";
	}

	int M;
	cin >> M;
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		cout << dp[a][b] << "\n";
	}
	
	return 0;
}