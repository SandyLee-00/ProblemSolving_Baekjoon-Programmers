// 1012번 유기농 배추
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAX = 50 + 1;

int ground[MAX][MAX];
int M, N, K;
int cnt = 0;
int visited[MAX][MAX];

void DFS(int x, int y){
	visited[x][y] = 1;
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = {1, -1, 0, 0};

	for(int i = 0; i < 4; i++){
		int n_x = x + dx[i];
		int n_y = y + dy[i];

		if(ground[n_x][n_y] == 1 && visited[n_x][n_y] == 0){
			DFS(n_x, n_y);
		}
	}
}
void reset(){
	for(int i = 0; i <= M; i++){
		for(int j = 0; j <= N; j++){
			ground[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	
	for(int i = 0; i < T; i++){
		// 배추 좌표 벡터에 입력받기
		cin >> M >> N >> K;
		for(int j = 0; j < K; j++){
			int x, y;
			cin >> x >> y;
			ground[x][y] = 1;
		}
		for(int k = 0; k <= M; k++){
			for(int l = 0; l <= N; l++){
				if(visited[k][l] == 0 && ground[k][l] == 1){
					DFS(k, l);
					cnt += 1;
				}
			}
		}
		cout << cnt << "\n";
		reset();
		M, N, K = 0;
		cnt = 0;
	}
	return 0;
}