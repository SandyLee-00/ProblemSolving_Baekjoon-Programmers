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

int v[105][105];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			v[i][j] = INT_MAX;
		}
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> v[i][j];
		}
	}

	// a - b && b - c이면 a - c 있다고 업데이트 하기
	for(int fir = 0; fir < N; fir++){
		for(int sec = 0; sec < N; sec++){
			for(int trd = 0; trd < N; trd++){
				if(v[fir][sec] == 1 && v[sec][trd] == 1){
					v[fir][trd] = 1;
				}
			}
		}
	}

	for(int fir = 0; fir < N; fir++){
		for(int sec = 0; sec < N; sec++){
			for(int trd = 0; trd < N; trd++){
				if(v[fir][sec] == 1 && v[sec][trd] == 1){
					v[fir][trd] = 1;
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