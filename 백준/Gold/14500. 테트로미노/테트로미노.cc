// 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <climits>
using namespace std;

/*

*/

int v[505][505];
int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };
int vis[505][505];
int N;
int M;

long long MaxRes = 0;

void getRecur(int posi, int posj, int depth, long long sum) {

	
	
	if (depth == 3) {
		MaxRes = max(sum, MaxRes);
		
		return;
	}

	for (int d = 0; d < 4; d++) {
		int nposi = posi + di[d];
		int nposj = posj + dj[d];

		if (nposi < 0 || nposi >= N || nposj < 0 || nposj >= M) {
			continue;
		}
		if (vis[nposi][nposj] == 1) {
			continue;
		}
		vis[nposi][nposj] = 1;
		getRecur(nposi, nposj, depth + 1, sum + v[nposi][nposj]);
		vis[nposi][nposj] = 0;
	}

}

void getFShape(int posi, int posj) {
	long long tempSum = v[posi][posj];

	for (int d = 0; d < 4; d++) {
		int nposi = posi + di[d];
		int nposj = posj + dj[d];

		if (nposi < 0 || nposi >= N || nposj < 0 || nposj >= M) {
			continue;
		}
		else
			tempSum += v[nposi][nposj];
	}

	for (int d = 0; d < 4; d++) {
		int nposi = posi + di[d];
		int nposj = posj + dj[d];

		if (nposi < 0 || nposi >= N || nposj < 0 || nposj >= M) {
			MaxRes = max(tempSum, MaxRes);
		}
		else
		{
			MaxRes = max(tempSum - v[nposi][nposj], MaxRes);
			
		}
	}

}

void getRes(int posi, int posj) {
	vis[posi][posj] = 1;
	getRecur(posi, posj, 0, v[posi][posj]);
	vis[posi][posj] = 0;
	getFShape(posi, posj);

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			getRes(i, j);
		}
	}

	cout << MaxRes;

	return 0;
}