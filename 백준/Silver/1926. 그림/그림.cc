// 1926번 그림
#include<bits/stdc++.h>
using namespace std;

int cntP, cntMax;
int n, m;

int board[501][501];
int vis[501][501];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

queue<pair<int, int>> q;

void bfs(int a, int b){
	int cntTmp = 1;
	vis[a][b] = 1;
	q.push({a, b});
	
	while(!q.empty()){
		int pi = q.front().first;
		int pj = q.front().second;
		q.pop();
		for(int d = 0; d < 4; d++){
			int di = pi + dx[d];
			int dj = pj + dy[d];
			if(di < 0 || dj < 0 || di >= n || dj >= m) continue;
			if(vis[di][dj] == 0 && board[di][dj] == 1){
				vis[di][dj] = 1;
				cntTmp += 1;
				q.push({di, dj});
				// cout << di << " " << dj << "\n";
			}
		}
	}
	cntMax = max(cntMax, cntTmp);
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(vis[i][j] == 0 && board[i][j] == 1){
				cntP += 1;
				bfs(i, j);
				// cout << i << " " << j << "\n";
			}
		}
	}

	
	cout << cntP << "\n" << cntMax;
	
	return 0;
}