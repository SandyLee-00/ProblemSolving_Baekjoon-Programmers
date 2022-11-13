// 17615번 볼 모으기
#include<bits/stdc++.h>
using namespace std;
/*
1 롤케이크 10이상인 값들 저장 
- 10이면 결과 += 1
- 10의 배수 20 이상이면 v넣기
- 10이상 값들 저장

2 자르는 횟수 가능한 만큼 카운트
- 배수v에서 for문으로 가능한 만큼 결과 += 1, 이상이면 += 1;
- 자르는 횟수 남으면 10이상 값 10자리수 만큼 결과 += 1

*/

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int M; cin >> M;
	vector<int>ten;
	vector<int>nten;
	int res = 0;
	for(int i = 0; i < N; i++){
		int a; cin >> a;
		if(a == 10){
			res += 1;
		}
		else if(a % 10 == 0){
			ten.push_back(a);
		}
		else if(a > 10){
			nten.push_back(a);
		}
	}

	sort(ten.begin(), ten.end());
	
	for(int i = 0; i < ten.size(); i++){
		int cut = ten[i] / 10;
		if(M == 0) break;
		else if(M + 1 >= cut){
			res += cut;
			M -= cut - 1;
			}
		else{
			res += M;
			M = 0;
			}
		}
	
	for(int i = 0; i < nten.size(); i++){
		int cut = nten[i] / 10;
		if(M == 0) break;
		if(M >= cut){
			res += cut;
			M -= cut;
		}
		else{
			res += M;
			M = 0;
		}
	}

		
	cout << res;
	
	return 0;
}