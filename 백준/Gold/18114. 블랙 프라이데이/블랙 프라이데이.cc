// 1753번 최단경로
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*

*/
vector<int> v;
bool weights[100000009];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, C; cin >> N >> C;
	int res = 0;
	
	for(int i = 0; i < N; i++){
		int a; cin >> a;
		v.push_back(a);
		weights[a] = 1;
	}
	for(int i = 0; i < N; i++){
		if(v[i] == C){
			res = 1;
		}
	}

	for(int i = 0; i < N; i++){
		int targetW = C - v[i];
		if(targetW < 1) continue;
		if(weights[targetW] && targetW != v[i]){
			res = 1;
		}
	}

	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			int targetW = C - v[i] - v[j];
			if(targetW < 1) continue;
			if(weights[targetW] && targetW != v[i] && targetW != v[j]){
				res = 1;
			}
		}
	}
	cout << res;
	
	return 0;
}