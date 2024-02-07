// 9465번 스티커
/*
D X C
X D X

X X C
D X X

X D X
D X C

D X X
X X C

DP 사이즈 10만 넘는 것 어떻게 만들어놓지?

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
#include <sstream>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	
	while(T--){
		int n;
		cin >> n;
		vector<int> mat[2];
		
		for(int i = 0; i < n; i++){
			int a;
			cin >> a;
			mat[0].push_back(a);
		}
		for(int i = 0; i < n; i++){
			int a;
			cin >> a;
			mat[1].push_back(a);
		}

		int DP[2][100005];
		for(int i = 0; i < 100005; i++){
			DP[0][i] = 0;
			DP[1][i] = 0;
		}

		DP[0][0] = mat[0][0];
		DP[1][0] = mat[1][0];

		DP[0][1] = mat[0][1] + DP[1][0]; 
		DP[1][1] = mat[1][1] + DP[0][0];

		
		for(int i = 2; i < n; i++){
			DP[0][i] = mat[0][i] + max(DP[1][i-1], DP[1][i-2]);
			DP[1][i] = mat[1][i] + max(DP[0][i-1], DP[0][i-2]);
			// cout << DP[0][i] << " " << DP[1][i] << "\n";
		}
		cout << max(DP[0][n-1], DP[1][n-1]) << "\n";
		
	}


	return 0;
}