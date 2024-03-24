// 4386번 별자리 만들기
/*
mst
unionfind
피타고라스로 모든 엣지 길이 구하기
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

int parents[105];

int find(int node){
	if(parents[node] == node){
		return node;
	}
	else{
		return parents[node] = find(parents[node]);
	}
}

bool unionF(int from, int to){
	int pfrom = find(from);
	int pto = find(to);
	if(pfrom != pto){
		parents[pfrom] = pto;
		return true;
	}
	return false;
}


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	
	vector<pair<float, float>> v;
	v.push_back({0.f, 0.f});
	
	for(int i = 0; i < n; i++){
		float a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}

	vector<pair<float, ii>> edges;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			int node1 = i;
			int node2 = j;

			float dSquarex = (v[node1].first - v[node2].first) * (v[node1].first - v[node2].first);
			float dSquarey = (v[node1].second - v[node2].second) * (v[node1].second - v[node2].second);

			float d = sqrt(dSquarex + dSquarey);
			edges.push_back({d, {node1, node2}});
		}
	}

	sort(edges.begin(), edges.end());

	float res = 0.f;
	for(int i = 0; i < 105; i++){
		parents[i] = i;
	}

	for(int i = 0; i < edges.size(); i++){
		float cost = edges[i].first;
		int from = edges[i].second.first;
		int to = edges[i].second.second;

		if(unionF(from, to)){
			res += cost;
		}
	}

	cout << res;
	
	return 0;
}