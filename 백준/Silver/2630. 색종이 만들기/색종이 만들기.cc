// 2630번 색종이 만들기
#include <bits/stdc++.h>
using namespace std;
/*
1 size, v 입력받기
2 sol()로 cntW, cntB 추가하기

2 범위체크, 색깔 하나면 그 색 추가
아니면 4개로 나누어서 범위 체크 재귀
*/

int v[300][300];
int cntW = 0, cntB = 0;

void sol(int size, int pi, int pj){
	int color = v[pi][pj];
	int div = 0;
	for(int i = pi; i < pi + size; i++){
		for(int j = pj; j < pj + size; j++){
			if(color != v[i][j]){
				div = 1;
				break;
			}
		}
	}
	if(div == 0){
		if(color == 0)
			cntW += 1;
		else if(color == 1)
			cntB += 1;
	}
	else{
		sol(size/2, pi, pj);
		sol(size/2, pi+size/2, pj);
		sol(size/2, pi, pj+size/2);
		sol(size/2, pi+size/2, pj+size/2);
	}
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> v[i][j];
		}
	}
	sol(N, 0, 0);
	cout << cntW << "\n" << cntB;
	
	return 0;
}