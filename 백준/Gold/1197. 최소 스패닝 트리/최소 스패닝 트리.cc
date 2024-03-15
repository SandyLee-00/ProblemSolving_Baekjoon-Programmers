// 1197번 최소 스패닝 트리
/*
가중치 작은 순서로 정렬
작은 것부터 하나씩 연결하기
넣었을 때 사이클 체크하기

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

int nodes[10005];

int find(int node){
	if(node == nodes[node]){
		return node;
	}
	return nodes[node] = find(nodes[node]);
}

bool Union(int node1, int node2){
	node1 = find(node1);
	node2 = find(node2);

	if(node1 == node2){
		return false;
	}
	else{
		nodes[node1] = node2;
		return true;
	}
}


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int V, E;
	cin >> V >> E;

	vector<pair<int, pair<int, int>>> edges;
	// weight로 전체 에지 저장하기
	for(int i = 0; i < E; i++){
		int a, b, c;
		cin >> a >> b >> c;

		edges.push_back({c, {a, b}});
	}

	// 전체 엣지 weight로 정렬하기
	sort(edges.begin(), edges.end());

	// 전체 노드 parent 정보 초기화
	for(int i = 0; i < 10005; i++){
		nodes[i] = i;
	}

	int res = 0;

	// 하나씩 사이클 만드는지 체크하면서 넣기
	for(int i = 0; i < edges.size(); i++){
		auto edge = edges[i];
		int weight = edge.first;
		int node1 = edge.second.first;
		int node2 = edge.second.second;

		if(Union(node1, node2)){
			res += weight;
		}
	}
	cout << res;

	return 0;
}