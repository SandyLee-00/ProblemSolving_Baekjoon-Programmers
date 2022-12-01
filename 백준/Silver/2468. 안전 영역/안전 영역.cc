// 2468번 안전 영역
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
1 사이즈, 공간의 정보 입력
2 물 0 -> 가장 높은 것까지 비교
최대 결과값 갖기
vis 초기화, tmpArea = area

resetVis(height)
resetTmpArea(height)
bfs(i, j)

*/
const int MAX = 1005;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int vis[MAX][MAX];
int area[MAX][MAX];
int tmpArea[MAX][MAX];

queue<pair<int, int>> q;
int N; 

void resetVis(int h){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(area[i][j] > h)
				vis[i][j] = 0;
			else
				vis[i][j] = 1;
		}
	}
}
void resetTmpArea(int h){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(area[i][j] <= h)
				tmpArea[i][j] = 0;
			else 
				tmpArea[i][j] = area[i][j];
		}
	}
}

void bfs(int i, int j){
	q.push({i, j});
	vis[i][j] = 1;
	while(!q.empty()){
		int pi = q.front().first;
		int pj = q.front().second;
		q.pop();
		for(int d = 0; d < 4; d++){
			int ni = pi + dx[d];
			int nj = pj + dy[d];
			if(vis[ni][nj] == 0 && tmpArea[ni][nj] != 0){
				vis[ni][nj] = 1;
				q.push({ni, nj});
			}
		}
	}
}


int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int maxH = 0;
	int maxRes = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> area[i][j];
			maxH = max(area[i][j], maxH);
		}
	}
	for(int h = 0; h < maxH; h++){
		resetVis(h);
		resetTmpArea(h);
		int cnt = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(tmpArea[i][j] != 0 && vis[i][j] == 0){
					bfs(i, j);
					cnt += 1;
				}
			}
		}
		maxRes = max(maxRes, cnt);
	}
	cout << maxRes;
	
	return 0;
}