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
// a - b && b - c이면 a - c 있다고 업데이트 하기
*/

int v[105][105];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> v[i][j];
		}
	}

	// a - b && b - c이면 a - c 있다고 업데이트 하기 (X)
	// middle을 거쳐 from to로 가는 길 있는지 체크
	for(int mid = 0; mid < N; mid++){
		for(int from = 0; from < N; from++){
			for(int to = 0; to < N; to++){
				if(v[from][mid] == 1 && v[mid][to] == 1){
					v[from][to] = 1;
				}
			}
		}
	}

	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}