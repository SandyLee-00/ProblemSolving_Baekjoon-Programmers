// 23758번 중앙값 제거
#include<bits/stdc++.h>
using namespace std;
/*
1 2의 지수 배열 만들기
2 수 입력받기
3 크기 순 정렬하기
4 연산해야하는 범위 정하기
5 결과값 만큼 그 수 이하인 만큼 카운트 ++
6 결과 +1하기 0만들기 때문


*/

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<int> v;
	vector<int> v_pow2;
	for(int i = 0; i < N; i++){
		int a; cin >> a;
		v.push_back(a);
	}
	for(int i = 1; i <= 1000000000; i = i * 2){
		v_pow2.push_back(i);
	}
	sort(v.begin(), v.end());
	
	int mid = (N-1) / 2;
	int res = 0;
	
	for(int i = 0; i <= mid; i++){
		// cout << v[i] << " ";
		for(int j = 1; j < v_pow2.size(); j++){
			if(v_pow2[j] <= v[i]){
				res += 1;
			}
			else break;
		}
	}
	cout << res + 1;
	
	return 0;
}