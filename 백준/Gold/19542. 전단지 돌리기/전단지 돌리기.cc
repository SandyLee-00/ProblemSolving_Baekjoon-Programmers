// 
/*
각 노드의 depth 구하기, D보다 크면 방문 필요

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

const int MAX = 123458;
int depths[MAX];
vector<int> grp[MAX];
int N, S, D;
int res = 0;

int dfs(int node, int parentNode){

	// 연결된 모든 노드 돌기
	for(int i = 0; i < grp[node].size(); i++){
		// 부모 노드 패스
		if(grp[node][i] == parentNode){
			continue;
		}

		// 자식 노드의 값 max 업데이트 하기
		else{
			depths[node] = max(depths[node], dfs(grp[node][i], node) + 1);
		}
	}

	// depth 값 > D 이면 방문 필요
	if(depths[node] >= D && node != S){
		res += 1;
	}

	// cout << node << " " << depths[node] << "\n";
	return depths[node];
}


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S >> D;
	
	for(int i = 0; i < N-1; i++){
		int a, b;
		cin >> a >> b;
		grp[a].push_back(b);
		grp[b].push_back(a);
	}

	dfs(S, -1);

	cout << (res) * 2;
	
	return 0;
}