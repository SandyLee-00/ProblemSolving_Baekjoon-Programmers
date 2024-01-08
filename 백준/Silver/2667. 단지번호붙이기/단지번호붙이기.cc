// 2667번 단지번호붙이기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
using namespace std;

// DFS 연결된 단지 수 카운트, 방문 안한 곳 체크 출력

const int MAX = 25;
int N; 

int house[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int groupCnt = 1;
int memCnt = 0;
vector<int> memCntStore;

void DFS(int i, int j){
	house[i][j] = groupCnt;
	memCnt += 1;
	//cout << "memCnt : " << memCnt;

	for(int d = 0; d < 4; d++){
		int newx, newy;
		newx = dx[d] + i;
		newy = dy[d] + j;

		if(newx >= 0 && newx <= N - 1 &&
			newy >= 0 && newy <= N - 1 &&
			house[newx][newy] == 1){
			house[newx][newy] = groupCnt;
			DFS(newx, newy);
		}
	}
	
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;

	for(int i = 0; i < N; i++){
		string str;
		cin >> str;
		for(int j = 0; j < N; j++){
			house[i][j] = str[j] - '0';
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(house[i][j] == 1){
				groupCnt += 1;
				DFS(i, j);
				memCntStore.push_back(memCnt);
				memCnt = 0;
			}
		}
	}

	cout << groupCnt - 1 << "\n";

	sort(memCntStore.begin(), memCntStore.end());
	
	for(int i = 0; i < memCntStore.size(); i++){
		cout << memCntStore[i] << "\n";
	}
	
	return 0;
}