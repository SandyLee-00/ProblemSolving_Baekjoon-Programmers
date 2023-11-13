// 헌내기는 친구가 필요해
/*
bfs로 가능한 위치 큐에 넣기
P이면 res++하기
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <climits>
using namespace std;

const int MAXN = 605;
char map[MAXN][MAXN];
int n, m;
int res;
bool vis[MAXN][MAXN];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

struct Data{
	int posi;
	int posj;
};

void bfs(int starti, int startj){
	queue<Data> q;

	vis[starti][startj] = true;
	q.push(Data{starti, startj});

	while(1){
		if(q.empty()){
			break;
		}
		int pi = q.front().posi;
		int pj = q.front().posj;

		if(map[pi][pj] == 'P')
		{
			res++;
		}

		q.pop();

		for(int d = 0; d < 4; d++){
			int ni = pi + dx[d];
			int nj = pj + dy[d];

			if(ni >= n || ni < 0 || nj >= m || nj < 0){
				continue;
			}

			if(vis[ni][nj] == true || map[ni][nj] == 'X'){
				continue;
			}
			
			vis[ni][nj] = true;
			q.push(Data{ni, nj});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			vis[i][j] = false;
		}
	}

	int starti, startj;
	for(int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		for(int j = 0; j < m; j++){
			map[i][j] = tmp[j];
			if(map[i][j] == 'I'){
				starti = i;
				startj = j;
			}
		}
	}

	bfs(starti, startj);

	if(res == 0){
		cout << "TT";
	}
	else{
		cout << res;
	}
	

	return 0;
}