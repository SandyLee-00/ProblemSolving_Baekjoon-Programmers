// 7453번 합이 0인 네 정수
/*
3개는 그냥 고르기
4개째만 이진탐색으로 고르기 X

투포인터 + 이진탐색
벡터 2 + 2로 만들기 
-> 4000^3 * log4000 X
16'000'000 * log16'000'000

이진탐색에서 찾은 위치가 더 크면
앞으로 가야하니까 end pos로 땡기기
이부분 조건 반대로 넣어놨었다

AB도 정렬 필요 캐시 히트

검색 결과 결과 값이 여러개 나올 경우 안했다
찾은 값 -- ++ 하면서 ret+= 1 하기 X 값 다 동일하게 가능
lower_bound, upper_bound로 위치 찾아서 개수 구하기

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
#include <sstream>
using namespace std;
using ll = long long;
using si = pair<string, int>;

const int MAX = 4004;
int N;

bool binarySearch(ll target, vector<ll>& D){
	int start = 0;
	int end = D.size()-1;

	while(1){
		int pos = (start + end) / 2;
		if(D[pos] == target){
			return 1;
		}
		else if(start >= end){
			return 0;
		}

		else if(D[pos] > target){
			end = pos;
		}
		else if(D[pos] < target){
			start = pos + 1;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	vector<ll> A(N);
	vector<ll> B(N);
	vector<ll> C(N);
	vector<ll> D(N);

	vector<ll> VFir;
	vector<ll> VSec;

	for(int i = 0; i < N; i++){
		cin >> A[i] >> B[i] >> C[i] >> D[i];		
	}

	ll ans = 0;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			VFir.push_back(A[i] + B[j]);
			VSec.push_back(C[i] + D[j]);
		}
	}

	sort(VFir.begin(), VFir.end());
	sort(VSec.begin(), VSec.end());

	for(ll i = 0; i < VFir.size(); i++){
		// cout << -VFir[i] << "\n";
		//if(binarySearch(-VFir[i], VSec)){
			// cout << "FOUND\n";
			//ans += 1;
		//}

		auto upIter = upper_bound(VSec.begin(), VSec.end(), -VFir[i]);
		auto lowIter = lower_bound(VSec.begin(), VSec.end(), -VFir[i]);

		ans += (upIter - lowIter);

	}

	cout << ans;
	
	return 0;
}