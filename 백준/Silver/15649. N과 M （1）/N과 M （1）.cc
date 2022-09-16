// 15649번 N과 M (1)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
using namespace std;

const int MAX = 9;

int nums[MAX];
bool vis[MAX];
int N, M;

void DFS(int n, int cnt){
	if(cnt == M){
		// 개수 모으면 출력
		for(int i = 1; i <= M; i++){
			cout << nums[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	// 방문 안한 것 넣기
	for(int i = 1; i <= N; i++){
		if(vis[i] == 0){
			vis[i] = true;
			cnt += 1;
			nums[cnt] = i;
			DFS(i, cnt);
			cnt -= 1;
			vis[i] = false;
		}
	}
	
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	DFS(0,0);
	
	return 0;
}