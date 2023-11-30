// 11404번 플로이드
/*
from - to - middle 
전체 INF 채우기
자기 자신 0 채우기
from-middle + middle-to 이면 from-to 업데이트 하기 

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

const int MNODE = 105;
int res[MNODE][MNODE];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	int m;
	cin >> m;

	for(int i = 0; i < MNODE; i++){
		for(int j = 0; j < MNODE; j++){
			res[i][j] = 9999999;
			if(i == j){
				res[i][j] = 0;
			}
		}
	}

	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(res[a][b] > c){
			res[a][b] = c;

		}
	}
	
	for(int k = 1; k <= n; k++){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
				if(res[i][k] + res[k][j] < res[i][j]){
					// cout << i << " " << j << " " << k << " " << res[i][j] << " " << res[i][k] + res[k][j] << "\n";
					res[i][j] = res[i][k] + res[k][j];
				}
			}
		}
	}

	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(res[i][j] == 9999999){
				cout << "0 ";
			}
			else{
				cout << res[i][j] << " ";
			}
		}
		cout << "\n";
	}
	
	
	
	return 0;
}