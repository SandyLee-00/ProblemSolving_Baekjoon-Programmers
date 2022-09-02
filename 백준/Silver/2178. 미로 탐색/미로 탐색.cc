// 2178번 미로 탐색
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
using namespace std;

const int MAX = 100 + 1;
const int MAX_C = 1000000;
int N, M;
int map[MAX][MAX];
int res = 0;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int vis[MAX][MAX];
int dis[MAX][MAX];

queue<pair<int, int>> q;

void BFS(int x, int y){
	q.push(make_pair(x, y));
	int cnt = 0;
	vis[0][0] = 1;
	dis[0][0] = 1;
	
	while(!q.empty()){
		int _x = q.front().first;
		int _y = q.front().second;
		q.pop();
		cnt += 1;
		vis[0][0] = 1;
		dis[0][0] = 1;

		for(int i = 0; i < 4; i++){
			int nx = _x + dx[i];
			int ny = _y + dy[i];
		
			if(map[nx][ny] == 1 && vis[nx][ny] == 0){
				vis[nx][ny] = 1;
				q.push(make_pair(nx, ny));
				dis[nx][ny] = dis[_x][_y] + 1;
				
			}
		}
		
	}
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	for(int i = 0; i < N; i++){
		string str; cin >> str;
		for(int j = 0; j < M; j++){
			map[i][j] = str[j] - '0';
		}
	}
	
	BFS(0, 0);

	// for(int i = 0; i < N; i++){
	// 	for(int j = 0; j < M; j++){
	// 		cout << dis[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	cout << dis[N - 1][M - 1];
	
	return 0;
}