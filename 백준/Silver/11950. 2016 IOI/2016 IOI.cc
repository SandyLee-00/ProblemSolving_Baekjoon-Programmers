// 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*

*/

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	vector<int> Wcnt;
	vector<int> Bcnt;
	vector<int> Rcnt;
	
	for(int i = 0; i < N; i++){
		string str; cin >> str;
		int W = 0, B = 0, R = 0;
		for(int j = 0; j < M; j++){
			if(str[j] == 'W') W++;
			else if(str[j] == 'B') B++;
			else if(str[j] == 'R') R++;
		}
		Wcnt.push_back(W);
		Bcnt.push_back(B);
		Rcnt.push_back(R);
	}
	int res = 999999;
	for(int i = 1; i <= N-2; i++){
		// B 시작줄
		// W 칠했을 때 카운트
		for(int j = i + 1; j <= N-1; j++){
			// R 시작줄
			// B 칠했을 때 카운트
			// R 칠했을 때 카운트
			int tmp = 0;
			for(int lineW = 0; lineW < i; lineW++){
				tmp += Bcnt[lineW] + Rcnt[lineW];
			}
			for(int lineB = i; lineB < j; lineB++){
				tmp += Wcnt[lineB] + Rcnt[lineB];
			}
			for(int lineR = j; lineR < N; lineR++){
				tmp += Wcnt[lineR] + Bcnt[lineR];
			}
			res = min(tmp, res);
		}
	}
	cout << res;
	
	return 0;
}