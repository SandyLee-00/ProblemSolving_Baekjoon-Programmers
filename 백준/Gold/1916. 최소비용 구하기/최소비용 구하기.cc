// 1916번 최소비용 구하기
/*
노드 A-B만 원한다 그래도 다익스트라 쓰기...?
pq로 노드 더하면서 다른 노드에 대해서 전부 업데이트 
결과 출력 

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
using ll = long long;
using pa = pair<int, int>;

const int MV = 1005;
const int MVS = INT_MAX / 3;

int N, M;
vector<pair<int, int>> mat[MV];
int res[MV];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> M;

	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		mat[a].push_back({b, c});
	}

	for(int i = 0; i < MV; i++){
		res[i] = MVS;
	}

	int start, end;
	cin >> start >> end;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start});
	res[start] = 0;
	
	while(!pq.empty()){
		int mid = pq.top().second;
		int cost = pq.top().first;

		pq.pop();

		if(cost > res[mid]){
			continue;
		}
		
		for(int i = 0; i < mat[mid].size(); i++){
			int to = mat[mid][i].first;
			int ncost = mat[mid][i].second + cost;

			if(ncost < res[to]){
				pq.push({ncost, to});
				res[to] = ncost;
				
			}
		}
	}

	for(int i = 1; i <= N; i++){
		// cout << res[i] << " ";
	}
	
	cout << res[end];
	
	
	return 0;
}