// 2252번 줄 세우기
/*
차수카운팅
엣지 방향성 연결 정보 저장
q에 카운팅 정보로 노드 넣기
노드 빼면서 연결된 카운팅 정보 수정하기
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> counts(N+1);
	vector<vector<int>> grp(N+1);

	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		grp[a].push_back(b);
		counts[b] += 1;
	}

	queue<int> q;

	for(int i = 1; i <= N; i++){
		if(counts[i] == 0){
			q.push(i);
		}
	}

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		cout << cur << " ";

		for(int i = 0; i < grp[cur].size(); i++){
			int next = grp[cur][i];
			counts[next] -= 1;
			
			if(counts[next] == 0){
				q.push(next);
			}
		}
	}

	return 0;
}