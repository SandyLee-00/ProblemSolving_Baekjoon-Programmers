// 7569번 토마토
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int dx[] = {0,0,-1,1,0,0};
int dy[] = {-1,1,0,0,0,0};
int dz[] = {0,0,0,0,-1,1};
int X;
int Y;
int Z;
const int MAX = 100 + 1;

int v[MAX][MAX][MAX];
int days[MAX][MAX][MAX];
int vis[MAX][MAX][MAX];

queue<int> qz;
queue<int> qy;
queue<int> qx;

void bfs(){
	for(int z = 0; z < Z; z++){
		for(int y = 0; y < Y; y++){
			for(int x = 0; x < X; x++){
				if(v[z][y][x] == 1){
					vis[z][y][x] = 1;
					days[z][y][x] = 0;
					qz.push(z);
					qy.push(y);
					qx.push(x);
				}
				
			}
		}
	}
	while(!qz.empty()){
		int z = qz.front();
		int y = qy.front();
		int x = qx.front();
		qz.pop();
		qy.pop();
		qx.pop();
		
		for(int i = 0; i < 6; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		int nz = z + dz[i];

		if(nz >= 0 && nz < Z && ny >= 0 && ny < Y && nx >= 0 && nx < X){
			if(v[nz][ny][nx] == 0 && vis[nz][ny][nx] == 0){
				v[nz][ny][nx] = 1;
				vis[nz][ny][nx] = 1;
				days[nz][ny][nx] = days[z][y][x] + 1;
				qz.push(nz);
				qy.push(ny);
				qx.push(nx);
				//cout << "nz ny nx : " << nz << " "<< ny << " " << nx << "\n";
			}
		}
	}
	}

}

void print_v(){
	for(int z = 0; z < Z; z++){
		for(int y = 0; y < Y; y++){
			for(int x = 0; x < X; x++){
				cout << v[z][y][x] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> X >> Y >> Z;

	for(int z = 0; z < Z; z++){
		for(int y = 0; y < Y; y++){
			for(int x = 0; x < X; x++){
				cin >> v[z][y][x];
			}
		}
	}
	bfs();
	
	int max_day = 0;
	int unriped = 0;

	for(int z = 0; z < Z; z++){
		for(int y = 0; y < Y; y++){
			for(int x = 0; x < X; x++){
				if(v[z][y][x] == 0){
					cout << -1;
					unriped = 1;
					break;
				}
				max_day = max(max_day, days[z][y][x]);
			}
			if(unriped == 1) break;
		}
		if(unriped == 1) break;
	}
	if(unriped == 0){
		cout << max_day;
	}
	
	
	return 0;
}