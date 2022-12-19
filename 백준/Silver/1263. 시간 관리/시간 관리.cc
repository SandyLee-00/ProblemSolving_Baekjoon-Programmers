// 1263번 시간 관리
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*

*/

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<pair<int, int>> v;
	for(int i = 0; i < N; i++){
		int T, S; cin >> T >> S;
		v.push_back({S, T});
	}
	sort(v.begin(), v.end());

	int now = v[v.size() - 1].first;
	for(int i = v.size() - 1; i >= 0; i--){

		if(now > v[i].first){
			now = v[i].first;
		}
		now -= v[i].second;
		if(now < 0) now = -1;
	}
	cout << now;
	
	return 0;
}