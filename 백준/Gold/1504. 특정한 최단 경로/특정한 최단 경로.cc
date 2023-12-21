// 1504번 특정한 최단 경로
/* 
1 <-> u <-> v <-> node
1 <-> v <-> u <-> node

플와로 최단거리 구해놓고 min 값 구하기
800^3 정도면 할 만 할지도..?

u에서 다익스트라 
v에서 다익스트라 
-> min 값 구하기

[][] -> []벡터로 바꿔야지 존재하는 edge 쭉 pq에 담을 수 있다


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
#include <sstream>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int MAX = INT_MAX / 3;
const int MAXN = 810;

int fromUs[MAXN];
int fromVs[MAXN];

vector<ii> grp[MAXN];

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, E;
	cin >> N >> E;

	for(int i = 0; i < E; i++){
		int a, b, c;
		cin >> a >> b >> c;

		grp[a].push_back({c, b});
		grp[b].push_back({c, a});
	}

	int u, v;
	cin >> u >> v;

	// uv 초기화
	for(int i = 0; i < MAXN; i++){
		fromUs[i] = MAX;
		fromVs[i] = MAX;
		if(u == i){
			fromUs[i] = 0;
		}
		if(v == i){
			fromVs[i] = 0;
		}
	}

	// u에서 가는 최단거리 구하기
	priority_queue<ii, vector<ii>, greater<ii>> pq;

	// u에서 가는 엣지 넣기
	for(int i = 0; i < grp[u].size(); i++){
		pq.push(grp[u][i]);
		fromUs[grp[u][i].second] = grp[u][i].first;
	}

	// 이 엣지로 그 노드 가는게 더 싸면 가기
	// 
	while(!pq.empty()){
		int weight = pq.top().first;
		int thisNode = pq.top().second;

		pq.pop();

		// 그 노드 거치기
		for(int i = 0; i < grp[thisNode].size(); i++){
			int newVal = weight + grp[thisNode][i].first;
			int nextNode = grp[thisNode][i].second;

			if(newVal < fromUs[nextNode]){
				fromUs[nextNode] = newVal;
				pq.push({newVal, nextNode});
			}
		}
	}

	// u에서 가는 엣지 넣기
	for(int i = 0; i < grp[v].size(); i++){
		pq.push(grp[v][i]);
		fromVs[grp[v][i].second] = grp[v][i].first;
	}

	// 이 엣지로 그 노드 가는게 더 싸면 가기
	// 
	while(!pq.empty()){
		int weight = pq.top().first;
		int thisNode = pq.top().second;

		pq.pop();

		// 그 노드 거치기
		for(int i = 0; i < grp[thisNode].size(); i++){
			int newVal = weight + grp[thisNode][i].first;
			int nextNode = grp[thisNode][i].second;

			if(newVal < fromVs[nextNode]){
				fromVs[nextNode] = newVal;
				pq.push({newVal, nextNode});
			}
		}
	}

	for(int i = 1; i <= N; i++){
		// cout << fromUs[i] << " ";
	}

	// cout << "\n";

	for(int i = 1; i <= N; i++){
		// cout << fromVs[i] << " ";
	}

	ll uVal = LONG_LONG_MAX;
	ll vVal = LONG_LONG_MAX;
	ll res = LONG_LONG_MAX;

	// 1 - u - v - i
	// 1 - v - u - i

	// u == 1
	// v == i
	uVal = fromUs[1] + fromUs[v] + fromVs[N];
	vVal = fromVs[1] + fromVs[u] + fromUs[N];

		if(v == 1){
			vVal = INT_MAX;
		}

		if(u == N){
			uVal = INT_MAX;
		}

		// cout << uVal << " " << vVal << "\n";

		res = min(res, uVal);
		res = min(res, vVal);
	
	
	if(res >= MAX){
		res = -1;
	}

	cout << res;
	
	return 0;
}