// 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
이진탐색으로 값 출력하기

*/
vector<int>v;
int prt[15][1050];

void sol(int l, int r, int level){
	
	if(l >= r) return;
	prt[level][(l + r) / 2] = v[(l + r) / 2];
	sol(l, (l + r) / 2, level + 1);
	sol((l + r) / 2 + 1, r, level + 1);
	
}


int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int K; cin >> K;
	int N = pow(2, K) - 1;
	for(int i = 0; i < N; i++){
		int a; cin >> a;
		v.push_back(a);
	}
	sol(0, N, 0);
	for(int i = 0; i < 15; i++){
		int prtFlag = 0;
		for(int j = 0; j < 1050; j++){
			if(prt[i][j] != 0){
				cout << prt[i][j] << " ";
				prtFlag = 1;
			}
		}
		if(prtFlag)
			cout << "\n";
	}
	
	
	return 0;
}
