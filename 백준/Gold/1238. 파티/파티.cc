// 1238번 파티
/* 
플워로 모든 최단 경로 구하기
N -> X -> N 
최댓값 구하기

31퍼에서 틀렸다고 나온다 왜지...?

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

const int MAX = 1005;
const ll MAXW = LONG_LONG_MAX / 3;

ll v[MAX][MAX];

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, X;

	cin >> N >> M >> X;

	// 거리 MAXW로 초기화
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			v[i][j] = MAXW;
		}
	}

	// a->b인 weight c 입력
	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v[a][b] = c;
	}

	// 플워 k 거치는 경로 업데이트
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			if(v[i][k] == MAXW){
				continue;
			}
			for(int j = 1; j <= N; j++){
				v[i][j] = min(v[i][k] + v[k][j], v[i][j]);
				// cout << i << " " << j << " " << v[i][j] << "\n";
			}
		}
	}

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			// cout << v[i][j] << " ";
		}
		// cout << "\n";
	}

	ll res = 0;
	for(int i = 1; i <= N; i++){
		if(i == X){
			continue;
		}
		res = max(res, v[i][X] + v[X][i]);
	}

	cout << res;
	
	return 0;
}