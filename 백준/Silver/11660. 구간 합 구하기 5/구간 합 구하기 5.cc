// 11660번 구간 합 구하기 5
/*
누적 합 구하기 2차원 버전
1 2
3 4
4자리에 2 + 3 + 4 넣기
d[i-1][j] + d[i][j-1] + v[i][j]

왼쪽 위쪽 빼고 왼&&위 더하기 X
2차원 누적합은 다르게 풀어야한

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <set>
#include <sstream>
using namespace std;
using ll = long long;

const int MV = 1030;

int v[MV][MV];
ll sumV[MV][MV];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	int M;
	cin >> M;

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> v[i][j];
		}
	}

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			sumV[i][j] = - sumV[i-1][j-1] + sumV[i-1][j] + sumV[i][j-1] + v[i][j];
			// cout << sumV[i][j] << " ";
		}
		// cout << "\n";
	}

	for(int i = 0; i < M; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int res = sumV[x2][y2];
		res -= sumV[x1-1][y2];
		res -= sumV[x2][y1-1];
		res += sumV[x1-1][y1-1];

		cout << res << "\n";
	}
	
	
	return 0;
}