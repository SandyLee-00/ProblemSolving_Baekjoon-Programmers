// 7983번 내일 할거야
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*

*/
bool cmp(pair<int, int> a, pair<int, int> b){
	return a.first > b.first;
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
		v.push_back({b, a});
	}
	sort(v.begin(), v.end(), cmp);
	int now = v[0].first;
	for(int i = 0; i < n; i++){
		if(now > v[i].first)
			now = v[i].first;
		now -= v[i].second;
	}
	cout << now;
	
	return 0;
}