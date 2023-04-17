// 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
숫자 개수 카운트하기
2의 배수 배열 만들기

개수 / 2 만큼 다음 배열로 올리기
1인 최종 값 출력하기
2의 몇 배수인지 카운트 바로 넣는 방법?
*/

int cntK[150];

int getIdx(ll num)
{
	if(num == 0) return 100;

	int ret = 0;
	while(1){
		if(num == 1) break;
		num /= 2;
		ret++;
	}
	return ret;
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	
	for(int i = 0; i < N; i++){
		ll ai; cin >> ai;
		int idx = getIdx(ai);
		cntK[idx]++;
	}

	for(int i = 0; i < 70; i++){
		cntK[i + 1] += cntK[i] / 2;
	}
	
	int resK = 0;
	for(int i = 0; i < 70; i++){
		if(cntK[i] >= 1){
			resK = i;
		}
	}
	// cout << resK;

	ll res = 1ll << resK;
	cout << res;

	// for(int i = 0; i < 150; i++){
	// 	cout << cntK[i] << " ";
	// }
	
	return 0;
}