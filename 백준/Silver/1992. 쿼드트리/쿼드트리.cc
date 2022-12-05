// 1992번 쿼드트리
#include <bits/stdc++.h>
using namespace std;
/*
1 N, 영상 입력
2 sol(size, cnt, i, j)를 넣어서 res 채우기

2 범위 속 내용 체크 같으면 처음 숫자로 입력, 아니면 () 속 호출 채우기

*/

int v[70][70];
string res = "";

void sol(int size, int cnt, int pi, int pj){
	int state = v[pi][pj];
	int doRecur = 0;
	
	for(int i = pi; i < pi + size; i++){
		for(int j = pj; j < pj + size; j++){
			if(state != v[i][j]){
				doRecur = 1;
			}
		}
	}
	if(doRecur == 1){
		res += "(";
		sol(size / 2, 0, pi, pj);
		sol(size / 2, 2, pi, pj + size/2);
		sol(size / 2, 1, pi + size/2, pj);
		sol(size / 2, 3, pi + size/2, pj + size/2);
		res += ")";
	}
	else{
		res += (char)state;
	}
	
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N; cin >> N;
	for(int i = 0; i < N; i++){
		string str; cin >> str;
		for(int j = 0; j < N; j++){
			v[i][j] = str[j];
		}
	}
	sol(N, 0, 0, 0);

	cout << res;
}