// 11053번 가장 긴 증가하는 부분 수열
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
using namespace std;
/*
카운트 커지기만 하면 된다.
*/

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<int> A;
	for(int i = 0; i < N; i++){
		int a; cin >> a;
		A.push_back(a);
	}
	vector<int> cnt(N, 0);
	cnt[0] = 0;
	
	for(int i = 0; i < N; i++){
		int maxcnti = 0;
		for(int j = 0; j < i; j++){
			if(A[i] > A[j]){
				maxcnti = max(maxcnti, cnt[j] + 1);
			}
		}
		cnt[i] = maxcnti;
	}
	int res = 0;
	for(int i = 0; i < N; i++){
		// cout << cnt[i] << " ";
		res = max(res, cnt[i]);
	}
	cout << res + 1;
	
	return 0;
}