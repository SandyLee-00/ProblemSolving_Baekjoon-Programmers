// 11054번 가장 긴 바이토닉 부분 수열
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*

*/

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<int> v;
	vector<int> vSum(N, 0);
	for(int i = 0; i < N; i++){
		int a; cin >> a;
		v.push_back(a);
	}
	
	for(int i = 0; i < N; i++){
		int sum = 0;
		for(int j = 0; j < i; j++){
			if(v[i] > v[j]){
				sum = max(sum, vSum[j]);
			}
		}
		vSum[i] = sum + v[i];
	}
	int res = 0;
	for(int i = 0; i < N; i++){
		res = max(vSum[i], res);
		// cout << vSum[i] << " ";
	}
	cout << res;
	
	return 0;
}
