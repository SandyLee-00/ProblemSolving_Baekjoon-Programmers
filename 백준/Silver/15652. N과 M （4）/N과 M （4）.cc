// 15652번 N과 M (4)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
using namespace std;

const int MAX = 8;
int N, M;
int pos[MAX + 1];

void dfs(int n, int cnt){
	if(cnt == M){
		for(int i = 1; i <= cnt; i++){
			cout << pos[i] << " ";
		}
		cout << "\n";
		return;
	}
		
	for(int i = n; i <= N; i++){
		cnt += 1;
		pos[cnt] = i;
		dfs(i, cnt);
		cnt -= 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	dfs(1,0);
	
	return 0;
}