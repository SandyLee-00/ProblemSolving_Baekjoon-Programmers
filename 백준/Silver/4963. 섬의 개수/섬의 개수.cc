// 4963번 섬의 개수
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

const int MAX = 50 + 1;
int board[MAX][MAX];
int vis[MAX][MAX];
int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
queue<pair<int, int>> q;

void reset_board(){
	for(int y = 0; y < MAX; y++){
		for(int x = 0; x < MAX; x++){
			board[x][y] = 0;
			vis[x][y] = 0;
		}
	}
}

void BFS(int x, int y){
	vis[x][y] = 1;
	q.push(make_pair(x, y));
	
	while(!q.empty()){
		int _x = q.front().first;
		int _y = q.front().second;
		vis[_x][_y] = 1;
		q.pop();
		
		for(int i = 0; i < 8; i++){
			int x_p = _x + dx[i];
			int y_p = _y + dy[i];

			if(vis[x_p][y_p] == 0 && board[x_p][y_p] == 1){
				vis[x_p][y_p] = 1;
				q.push(make_pair(x_p, y_p));
			}
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while(1){
		
		int w, h; cin >> w >> h;
		if(w == 0 && h == 0) break;
		for(int y = 0; y < h; y++){
			for(int x = 0; x < w; x++){
				cin >> board[x][y];
			}
		}
		
		int cnt = 0;
		
		for(int y = 0; y < h; y++){
			for(int x = 0; x < w; x++){
				if(vis[x][y] == 0 && board[x][y] == 1){
					BFS(x, y);
					cnt += 1;
					//cout << x << " "<< y << "\n";
				}
			}
		}
		cout << cnt << "\n";
		cnt = 0;
		reset_board();
	}
	
	return 0;
}
