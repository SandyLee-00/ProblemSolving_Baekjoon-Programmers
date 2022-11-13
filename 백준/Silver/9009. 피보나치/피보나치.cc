// 9009번 피보나치
#include<bits/stdc++.h>
using namespace std;
/*
1 피보나치 수 배열에 저장해놓기
2 큰 순서대로 뺴기, 배열에 체크
3 결과 출력
4 원래대로 돌리기

1 long long에 for문으로 100.000.000까지 넣기
2 배열에서 그 수보다 바로 작은 값부터 찾아서 빼면서 방문에 체크하기
2 방문 배열 만들기
3 방문 배열 체크 되어있으면 그 인덱스 값 찾아서 출력
4 방문 배열 0 넣기

*/

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<long long> fib;
	
	fib.push_back(1);
	fib.push_back(1);
	fib.push_back(2);
	int v_size;
	
	for(int i = 3; i < 10000; i++){
		long long num = fib[i-1] + fib[i-2];
		fib.push_back(num);
		if(num >= 1000000000){
			v_size = i;
			break;
		}
	}
	
	vector<int> vis(v_size, 0);

	for(int i = 0; i < fib.size(); i++){
		//cout << fib[i] << " ";
	}

	int T; cin >> T;
	while(T--){
		long long n; cin >> n;
		long long n_tmp = n;
		for(int i = v_size; i >= 0; i--){
			if(fib[i] <= n_tmp){
				n_tmp -= fib[i];
				vis[i] = 1;
			}
		}
		for(int i = 0; i < v_size; i++){
			if(vis[i] == 1){
				cout << fib[i] << " ";
				vis[i] = 0;
			}
		}
		cout << "\n";
		
	}
	
	
	return 0;
}