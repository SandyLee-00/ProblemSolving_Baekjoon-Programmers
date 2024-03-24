// 1647번 도시 분할 계획
/*
mst 만들기
union-find
- root인 두 노드를 합쳐야 한다 
- mst 만들고 가장 마지막 엣지 뺴야지 두 개로 분리된다 
- 경로압축 안해서 시간초과 났다 
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

int parents[100005];

int find(int node){
	if(parents[node] == node){
		return node;
	}
	else{
		return parents[node] = find(parents[node]);
	}
}

bool unionf(int from, int to){
	int pfrom = find(from);
	int pto = find(to);
	// cout << pfrom << " " << pto << " ";
	
	if(pfrom != pto){
		parents[pfrom] = pto;
		return true;
	}
	
	return false;
}

void printp(){
	for(int i = 0; i < 15; i++){
		cout << parents[i] << " ";
	}
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<pair<int, ii>> v;

	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;

		v.push_back({c, {a, b}});
	}
	sort(v.begin(), v.end());

	int res = 0;

	for(int i = 0; i < 100005; i++){
		parents[i] = i;
	}

	int last = 0;
	
	for(int i = 0; i < M; i++){
		int from = v[i].second.first;
		int to = v[i].second.second;
		int cost = v[i].first;

		if(unionf(from, to)){
			// printp();
			res += cost;
			// cout << res << "\n";
			last = cost;
		}
	}

	cout << res - last;
	
	return 0;
}