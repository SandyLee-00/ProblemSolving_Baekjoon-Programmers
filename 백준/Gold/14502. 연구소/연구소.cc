// 14502번 연구소
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
1 배열에 원래 판 입력
2 벽 가능 위치 vector<pair<int,int>> i, j입력
3 벽 번호 3개 중복없이 순서없이 선택 
3 각 선택에서 벽 만들고 bfs해서 퍼지게 하기, 안전영역 res 업데이트
*/
int v[10][10];
int tmp[10][10];
int tmpVis[10][10];
int res;
int selWallNum[100];
vector<pair<int, int>> wall;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int N, M; 

void resetTmp(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			tmp[i][j] = v[i][j];
		}
	}
}

void dfs(){
	stack<pair<int, int>> s;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(tmp[i][j] == 2)
				s.push({i, j});
		}
	}
	while(!s.empty()){
		int pi = s.top().first;
		int pj = s.top().second;
		s.pop();
		for(int d = 0; d < 4; d++){
			int ni = pi + dx[d];
			int nj = pj + dy[d];
			if(ni >= 0 && ni < N && nj >= 0 && nj < M){
				if(tmp[ni][nj] == 0){
					tmp[ni][nj] = 2;
					s.push({ni,nj});
				}
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(tmp[i][j] == 0)
				cnt++;
		}
	}
	res = max(cnt, res);
}

void selectWall(int now, int cnt){
	//벽 번호 3개 중복없이 순서없이 선택 
	if(cnt == 3){
		resetTmp();
		for(int i = 0; i < 100; i++){
			if(selWallNum[i] == 1){
				int pi = wall[i].first;
				int pj = wall[i].second;
				tmp[pi][pj] = 1;
			}
		}
		dfs();
		return;
	}
	for(int i = now + 1; i < wall.size(); i++){
		selWallNum[i] = 1;
		cnt += 1;
		selectWall(i, cnt);
		selWallNum[i] = 0;
		cnt -= 1;
	}
}




int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> v[i][j];
			if(v[i][j] == 0){
				wall.push_back({i, j});
			}
		}
	}
	selectWall(-1, 0);
	cout << res;
	
	return 0;
}