// 2206번 벽 부수고 이동하기
/*
BFS + 
0: 벽 안 부순 맵 이동 카운트
1: 벽 부순 맵 이동 카운트 

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
using ll = long long;

const int MV = 1005;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int map[MV][MV];
int vis[MV][MV][2];

struct D{
int pi;
int pj;
int cnt;
bool isused;
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		string tmp;
		cin >> tmp;
		for(int j = 0; j < tmp.size(); j++){
			map[i][j] = tmp[j] - '0';
		}
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			vis[i][j][0] = 999999;
			vis[i][j][1] = 999999;
		}
	}

	queue<D> q;
	q.push({0, 0, 1, false});
	vis[0][0][0] = 1;
	vis[0][0][1] = 1;

	while(!q.empty()){
		int qpi = q.front().pi;
		int qpj = q.front().pj;
		int qcnt = q.front().cnt;
		bool qisused = q.front().isused;

		q.pop();

		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				// cout << vis[i][j][0];
			}
			// cout << "\n";
		}
		// cout << "\n";

		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				// cout << vis[i][j][1];
			}
			// cout << "\n";
		}
		// cout << "\n";

		for(int i = 0; i < 4; i++){
			int npi = qpi + dx[i];
			int npj = qpj + dy[i];
			int ncnt = qcnt + 1;

			// cout << npi << " " << npj << " " << ncnt << "\n";

			// 범위 벗어났을 때 패스
			if(npi < 0 || npi >= N || npj < 0 || npj >= M){
				continue;
			}

			// ncnt가 더 클 때 패스
			if(ncnt >= vis[npi][npj][0] && qisused == false || 
				ncnt >= vis[npi][npj][1] && qisused == true){
				continue;
			}

			// 벽일 때 부수기 
			if(map[npi][npj] == 1 && qisused == false){
				q.push({npi, npj, ncnt, true});
				vis[npi][npj][1] = ncnt;
			}

			// 갈 수 있을 때 이미 벽 쓴 상태
			if(map[npi][npj] == 0 && qisused == true){
				q.push({npi, npj, ncnt, true});
				vis[npi][npj][1] = ncnt;
			}

			// 갈 수 있을 때 벽 안 쓴 상태
			if(map[npi][npj] == 0 && qisused == false){
				q.push({npi, npj, ncnt, false});
				vis[npi][npj][0] = ncnt;
			}
		}
	}
	int res = min(vis[N-1][M-1][0], vis[N-1][M-1][1]);
	if(res == 999999){
		res = -1;
	}
	
	cout << res;

	return 0;
}
