// 9466번 텀 프로젝트
/*
dfs
visited done
방문한 것 다시 방문하면 사이클 체크하기
사이클 안 되어있으면 그냥 done 체크하기
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

int cnt;

void dfs(int node, vector<int>& v, vector<int>& visited, vector<int>& done) {
	visited[node] = 1;
	int nextNode = v[node];

	if (visited[nextNode] == 0) {
		dfs(nextNode, v, visited, done);
	}

	else if (visited[nextNode] == 1 && done[nextNode] == 0) {
		int tmp = node;
		while (1) {
			if (done[tmp] == 1) {
				break;
			}
			done[tmp] = 1;
			cnt += 1;
			tmp = v[tmp];
		}
	}

	done[node] = 1;

	return;
}


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> v;
		vector<int> visited(N + 1);
		vector<int> done(N + 1);
		cnt = 0;

		v.push_back(-1);
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}

		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0) {
				dfs(i, v, visited, done);
			}
		}

		cout << N - cnt << "\n";
	}





	return 0;
}