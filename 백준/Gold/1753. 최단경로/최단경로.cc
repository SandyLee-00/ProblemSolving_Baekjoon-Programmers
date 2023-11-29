// 1753번 최단경로
/*


*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <set>
#include <sstream>
using namespace std;

const int VMAX = 20005;
vector<pair<int, int>> node[VMAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int res[VMAX];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int V, E;
	cin >> V >> E;
	int K;
	cin >> K;

	// 입력 엣지 수만큼 vector<pair<int, int>> 에 node[from][{to, weight}] 넣기
	while(E--){
		int u, v, w;
		cin >> u >> v >> w;

		node[u].push_back({v, w});
	}

	// res 초기화하기
	for(int i = 0; i < VMAX; i++){
		res[i] = INT_MAX;
	}

	// 처음 노드 거리 0
	res[K] = 0;

	// pq에 시작 노드 방문 넣기 {weight, from}
	pq.push({0, K});

	// pq 돌면서 하나씩 빼기
	// weight, from 가져오기
	// node 연결 상태에서 from-to 체크해서 더 짧으면 
	// 값 업데이트 하고 pq에 넣어서 그 점 기준으로 다시 계산할 수 있게 하기

	while(!pq.empty()){
		int from = pq.top().second;
		int weight = pq.top().first;
		pq.pop();

		for(int i = 0; i < node[from].size(); i++){
			int to = node[from][i].first;
			int sumWeight = node[from][i].second + weight;

			if(sumWeight < res[to]){
				res[to] = sumWeight;
				pq.push({sumWeight, to});
			}
		}
	}
	for(int i = 1; i <= V; i++){
		if(res[i] == INT_MAX){
			cout << "INF\n";
		}
		else{
			cout << res[i] << "\n";
		}
	}
	
	
	return 0;
}