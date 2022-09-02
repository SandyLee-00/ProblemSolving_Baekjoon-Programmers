// 7576번 토마토
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

const int MAX = 1000 + 1;
int M, N;
int day_cnt;
int map[MAX][MAX];
int days[MAX][MAX];
int vis[MAX][MAX];
queue<pair<int, int>>q;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void print_days(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << days[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}

void print_map(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}

void BFS(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(map[i][j] == 1) {
				vis[i][j] = 1;
				days[i][j] = 0;
				q.push(make_pair(i, j));
			}
		}
	}

	while(!q.empty()){
	int _x = q.front().first;
	int _y = q.front().second;
	q.pop();
	
	for(int i = 0; i < 4; i++){
		int nx = _x + dx[i];
		int ny = _y + dy[i];

		if(map[nx][ny] == 0 && vis[nx][ny] == 0 && 
			nx >= 0 && ny >= 0 && nx <= N - 1 && ny <= M - 1){
			// print_days();
			vis[nx][ny] = 1;
			days[nx][ny] = days[_x][_y] + 1;
			map[nx][ny] = 1;
			q.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N; // M 가로 N 세로
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}
	BFS();
	
	int ans = 0;
	int minus = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(map[i][j] == 0) {
				ans = -1;
				minus = 1;
			}
			else if(map[i][j] != 0) ans = max(ans, days[i][j]);
		}
	}
	if(minus == 1){
		cout << -1;
	}
	else{
		cout << ans << "\n";
	}
	return 0;
}
