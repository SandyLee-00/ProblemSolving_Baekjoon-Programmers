// 18870번 좌표 압축
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
1 원본 벡터 입력
2 원복 벡터 복사한 벡터 만들기
3 tmp벡터 정렬, unique로 중복 제거
4 lowerbound로 위치 찾아내서 시작점에서 뺀 인덱스 출력하기

*/


int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<int> v(N, 0);
	vector<int> tmpV(N, 0);
	for(int i = 0; i < N; i++){
		cin >> v[i];
		tmpV[i] = v[i];
	}
	sort(tmpV.begin(), tmpV.end());
	tmpV.erase(unique(tmpV.begin(), tmpV.end()), tmpV.end());
	
	for(int i = 0; i < N; i++){
		auto iter = lower_bound(tmpV.begin(), tmpV.end(), v[i]) - tmpV.begin();
		cout << iter << " ";
	}
	
	return 0;
}