// 15650번 N과 M (2)
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
int vis[MAX];
int nums[MAX];
int N, M;

void dfs(int n, int cnt){
	if(cnt == M){
		for(int i = 1; i <= M; i++){
			cout << nums[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i = n; i <= N; i++){
		if(vis[i] == 0){
			vis[i] = 1;
			cnt += 1;
			nums[cnt] = i;
			//cout << "dfs(" << i << ", " << cnt << ")\n";
			dfs(i, cnt);
			
			cnt -= 1;
			vis[i] = false;
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M; // N까지 자연수 M개
	dfs(1, 0);
	
	return 0;
}