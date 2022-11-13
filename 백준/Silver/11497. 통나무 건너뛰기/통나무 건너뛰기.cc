// 11497번 통나무 건너뛰기
#include<bits/stdc++.h>
using namespace std;
/*
1 v 입력, 정렬하기
2 v에서 홀수 인덱스 차이 구하기
3 끝부터 짝수 인덱스 차이 구하기
4 결과 출력

*/

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	while(T--){
		
		vector<int> v;
		int v_size; cin >> v_size;
		for(int i = 0; i < v_size; i++){
			int a; cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());

		int res = 0;

		for(int i = 0; i < v_size - 1; i++){
			int diff;
			if(i == v_size - 2){
				diff = v[v_size-1] - v[i];
			}
			else{
				diff = v[i+2] - v[i];
			}
			if(diff > res){
				res = diff;
				//cout << v[i+2] << " " << v[i] << " ";
				//cout << res << "\n";
			}
		}
		cout << res << "\n";
		//cout << "\n";
	}
	
	return 0;
}