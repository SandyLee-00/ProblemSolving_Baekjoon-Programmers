// 10026번 적록색약
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int N; 
// vector<vector<int>> v(N, vector<int>(N));
// vector<vector<int>> vis(N, vector<int>(N));
int v[101][101];
int vis[101][101];

void dfs(int y, int x){
	vis[y][x] = 1;

	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny >= 0 && ny < N && nx >= 0 && nx < N){
			if(vis[ny][nx] == 0 && v[y][x] == v[ny][nx]){
				dfs(ny, nx);
				//cout << "ny nx : " << ny << " " << nx << "\n";
			}
		}
	}
}

void print_vis(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << vis[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void reset_vis(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			vis[i][j] = 0;
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	vector<string> vs(N);
	
	for(int i = 0; i < N; i++){
		cin >> vs[i];
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(vs[i][j] == 'R') v[i][j] = 1;
			else if(vs[i][j] == 'G') v[i][j] = 2;
			else if(vs[i][j] == 'B') v[i][j] = 3;
		}
	}
	
	int cnt = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(vis[i][j] == 0){
				dfs(i, j);
				cnt += 1;
				// print_vis();
			}
		}
	}
	cout << cnt << " ";

	cnt = 0;
	reset_vis();
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(v[i][j] == 2) v[i][j] = 1;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(vis[i][j] == 0){
				dfs(i, j);
				cnt += 1;
			}
		}
	}
	
	cout << cnt << " ";
	
	return 0;
}