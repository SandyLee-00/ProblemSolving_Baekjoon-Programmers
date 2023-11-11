// 쉬운 최단거리
/*
bfs로 입력 지점부터 모든 곳 방문하기
res에 cnt 넣기
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <climits>
using namespace std;

int map[1005][1005];
int n, m;
int resMap[1005][1005];
bool vis[1005][1005];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

struct Data{
	int posi;
	int posj;
	int cnt;
};

void bfs(int starti, int startj){
	queue<Data> q;

	vis[starti][startj] = true;
	q.push(Data{starti, startj, 0});

	while(1){
		if(q.empty()){
			break;
		}
		int pi = q.front().posi;
		int pj = q.front().posj;
		int pc = q.front().cnt;
		resMap[pi][pj] = pc;

		q.pop();

		for(int d = 0; d < 4; d++){
			int ni = pi + dx[d];
			int nj = pj + dy[d];

			if(ni >= n || ni < 0 || nj >= m || nj < 0){
				continue;
			}

			if(vis[ni][nj] == true || map[ni][nj] == 0){
				continue;
			}
			
			vis[ni][nj] = true;
			q.push(Data{ni, nj, pc + 1});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			resMap[i][j] = -1;
			vis[i][j] = false;
		}
	}

	int starti, startj;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
			if(map[i][j] == 0){
				resMap[i][j] = 0;
			}
			if(map[i][j] == 2){
				starti = i;
				startj = j;
				resMap[i][j] = 0;
			}
		}
	}

	bfs(starti, startj);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << resMap[i][j] << " ";
		}
		cout << "\n";
	}
	

	return 0;
}