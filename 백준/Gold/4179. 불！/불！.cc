// 4179번 불!
#include <bits/stdc++.h>
using namespace std;
/*
지훈이가 시간에 따라 이동할 수 있는 위치 bfs로 표시
불이 시간에 따라 이동하는 위치 표시
지훈 값 < 불 이면 이동 가능

*/
const int MAX = 1005;

int R, C;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int maze[MAX][MAX];
int movJ[MAX][MAX];
int movF[MAX][MAX];

queue<pair<int, int>> q;
queue<int> cntq;

void bfsJ(int fir, int sec){
	q.push({fir, sec});
	cntq.push(1);
	while(!q.empty()){
		int pi = q.front().first;
		int pj = q.front().second;
		int cnt = cntq.front();
		q.pop();
		cntq.pop();
		for(int d = 0; d < 4; d++){
			int ni = pi + dx[d];
			int nj = pj + dy[d];
			if(movJ[ni][nj] == 0 && maze[ni][nj] == 1){
				movJ[ni][nj] = cnt + 1;
				q.push({ni, nj});
				cntq.push(cnt + 1);
			}
		}
	}
}

void bfsF(int fir, int sec){
	q.push({fir, sec});
	cntq.push(1);
	while(!q.empty()){
		int pi = q.front().first;
		int pj = q.front().second;
		int cnt = cntq.front();
		q.pop();
		cntq.pop();
		for(int d = 0; d < 4; d++){
			int ni = pi + dx[d];
			int nj = pj + dy[d];
			if(movF[ni][nj] == 0 && maze[ni][nj] != 0){
				movF[ni][nj] = cnt + 1;
				q.push({ni, nj});
				cntq.push(cnt + 1);
			}
			else if(movF[ni][nj] > cnt + 1 && maze[ni][nj] != 0){
				movF[ni][nj] = cnt + 1;
				q.push({ni, nj});
				cntq.push(cnt + 1);
			}
		}
	}
}
void prt(){
	for(int i = 0 ; i < R; i++){
		for(int j = 0; j < C; j++){
			cout << movJ[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	for(int i = 0 ; i < R; i++){
		for(int j = 0; j < C; j++){
			cout << movF[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> R >> C;
  int jPosi, jPosj;

  for (int i = 0; i < R; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < C; j++) {
      if (str[j] == '#') {
        maze[i][j] = 0;
      } else if (str[j] == '.') {
        maze[i][j] = 1;
      } else if (str[j] == 'J') {
        maze[i][j] = 2;
        movJ[i][j] = -1;
        jPosi = i;
        jPosj = j;
      } else if (str[j] == 'F') {
        maze[i][j] = 3;
        movF[i][j] = -1;
      }
    }
  }
  bfsJ(jPosi, jPosj);

	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(maze[i][j] == 3){
				bfsF(i, j);
			}
		}
	}
	

	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(maze[i][j] == 3){
				bfsF(i, j);
			}
		}
	}
	// prt();
	int res = 5000;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			// ㅁ 벽 아님, 지훈 < 불, 빠른 시간 저장, -1이면 불가능
			if(i == 0 || j == 0 || i == R-1 || j == C-1){
				if(jPosi == 0 || jPosj == 0 || jPosi == R-1 || jPosj == C-1){
					res = 1;
				}
				if(movJ[i][j] < movF[i][j] && movJ[i][j] != 0 || movF[i][j] == 0 && movJ[i][j] != 0){
					res = min(movJ[i][j], res);
				}
			}
		}
	}
	if(res != 5000)
		cout << res;
	else
		cout << "IMPOSSIBLE";

  return 0;
}