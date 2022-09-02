// 11724번 연결 요소의 개수
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAX = 1001;

int map[MAX][MAX];
int visited[MAX];
int N, M;

void DFS(int x){
	visited[x] = 1;

	for(int i = 1; i <= N; i++){
		if(map[x][i] == 1 && visited[i] == 0){
			DFS(i);
			//cout << i << "\n";
		}
	}
	
	
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	
	for(int i = 0; i < M; i++){
		int x, y;
		cin >> x >> y;
		
		map[x][y] = 1;
		map[y][x] = 1;
	}
	int cnt = 0;
	for(int i = 1; i <= N; i++){
		if(visited[i] == 0){
			DFS(i);
			cnt += 1;
		}
		
	}

	cout << cnt;
	
	return 0;
}