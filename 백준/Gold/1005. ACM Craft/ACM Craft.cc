// 1005번 ACM Craft
/*
위상정렬
counts 로 앞에 몇 개 있는지 체크
connects로 내가 갖고있는 연결 노드
Ds로 몇 초 걸리는지
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

	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;

		vector<int> Ds(N + 1);
		vector<int> orders(N + 1);
		vector<vector<int>> con(N + 1);
		for (int i = 1; i <= N; i++) {
			int d;
			cin >> d;
			Ds[i] = d;
		}
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			orders[b] += 1;
			con[a].push_back(b);
		}

		int target;
		cin >> target;

		queue<ii> q;

		// ordre 0인 노드 시작으로 넣기
		for (int i = 1; i < orders.size(); i++) {
			if (orders[i] == 0) {
				q.push({ i, Ds[i] });
			}
		}

		// 각 노드별로 cost 구하기
		// 뺄 노드에서 연결된 모든 노드 구하기
		// 연결 하나씩 빼주기
		// 연결된 다른 것이 없으면 q에 넣기

		vector<int> nodeMaxCost(N + 1);
		while (!q.empty()) {
			int nowNode = q.front().first;
			int cost = q.front().second;
			q.pop();

			if(nowNode == target){
				cout << cost << "\n";
				break;
			}

			for (int i = 0; i < con[nowNode].size(); i++) {
				int node = con[nowNode][i];
				orders[node] -= 1;
				nodeMaxCost[node] = max(cost, nodeMaxCost[node]);

				if (orders[node] == 0) {
					q.push({ node, Ds[node] + nodeMaxCost[node]});

					// cout << node << " " << Ds[node] + nodeMaxCost[node] << "\n";
				}
			}
		}
	}

	return 0;
}