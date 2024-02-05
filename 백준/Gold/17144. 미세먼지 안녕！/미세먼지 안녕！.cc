// 17144번 미세먼지 안녕!
/*
확산하는거 한 칸씩 해놓으면 안된다 정해질 값 들고있다가 끝까지 계산되면 반영 되어야한다 

Add 배열 만들어서 변화만 갖고있기
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
using ii = pair<int, int>;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int R, C, T;
int mat[55][55];
int tempMat[55][55];

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C >> T;

	int pos1, pos2;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> mat[i][j];
			if(mat[i][j] == -1){
				pos1 = i-1;
				pos2 = i;
			}
		}
	}

	while(T--){

	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			// #확산
			if(mat[i][j] >= 0){
				int cnt = 0;
				for(int d = 0; d < 4; d++){
					int ni = i + dx[d];
					int nj = j + dy[d];
					if(ni < 0 || ni >= R || nj < 0 || nj >= C){
						continue;
					}
					else if(ni == pos1 && nj == 0 || ni == pos2 && nj == 0){
						continue;
					}
					// x/5 한 값 넣기
					tempMat[ni][nj] += mat[i][j] / 5;
					cnt += 1;
				}
				tempMat[i][j] -= (mat[i][j] / 5) * cnt;
			}
		}
	}

	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			mat[i][j] += tempMat[i][j];
			tempMat[i][j] = 0;
		}
	}

	// # 위
	for(int i = pos1-1; i > 0; i--){
		mat[i][0] = mat[i-1][0];
	}
	for(int j = 0; j < C-1; j++){
		mat[0][j] = mat[0][j+1];
	}
	for(int i = 0; i < pos1; i++){
		mat[i][C-1] = mat[i+1][C-1];
	}
	for(int j = C-1; j > 1; j--){
		mat[pos1][j] = mat[pos1][j-1];
	}

	// # 아래
	for(int i = pos2+1; i < R; i++){
		mat[i][0] = mat[i+1][0];
	}
	for(int j = 0; j < C-1; j++){
		mat[R-1][j] = mat[R-1][j+1];
	}
	for(int i = R; i > pos2; i--){
		mat[i][C-1] = mat[i-1][C-1];
	}
	for(int j = C-1; j > 1; j--){
		mat[pos2][j] = mat[pos2][j-1];
	}

	mat[pos1][1] = 0;
	mat[pos2][1] = 0;

		// cout << "\n";

		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				// cout << mat[i][j] << " ";
			}
			// cout << "\n";
		}
		
	}

	int res = 0;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(mat[i][j] > 0){
				res += mat[i][j];
			}
		}
	}

	cout << res;


	return 0;
}