// 11054번 가장 긴 바이토닉 부분 수열
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
증가하는 수열 dp
감소하는 수열 dp
각 위치에서 증가 + 감소 -1 최댓값
*/

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<int> v(N, 0);
	vector<int> l(N, 0);
	vector<int> r(N, 0);
	int res = 0;
	
	for(int i = 0; i < N; i++){
		cin >> v[i];
	}
	// 증가하는 수열 dp
	for(int i = 0; i < N; i++){
		for(int j = 0; j < i; j++){
			if(v[i] > v[j])
				l[i] = max(l[j], l[i]);
		}
		l[i] += 1;
	}
	// 감소하는 수열 dp
	for(int i = N-1; i >= 0; i--){
		for(int j = N-1; j > i; j--){
			if(v[i] > v[j])
				r[i] = max(r[j], r[i]);
		}
		r[i] += 1;
	}
	for(int i = 0; i < N; i++){
		res = max(l[i] + r[i], res);
	}
	cout << res - 1;
	
	return 0;
}