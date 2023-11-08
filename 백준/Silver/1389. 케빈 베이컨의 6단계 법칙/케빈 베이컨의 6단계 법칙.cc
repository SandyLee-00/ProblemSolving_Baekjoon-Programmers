// 케빈 베이컨의 6단계 법칙
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <climits>
using namespace std;

/*
전부 INF두고 minRes 업데이트 한다 
플로이드 워셜로 전체 최단거리 구해놓는다
결과에서 가장 작은 사람 인덱스 리턴하기

INT_MAX에서 +1 하면 오버플로우여서 - 1
*/

int links[105][105];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	int M;
	cin >> M;

	for(int i = 0; i < 105; i++){
		for(int j = 0; j < 105; j++){
			links[i][j] = 10000;
		}
	}

	while(M--){
		int A;
		cin >> A;
		int B;
		cin >> B;

		links[A][B] = 1;
		links[B][A] = 1;
	}

	for(int mid = 1; mid <= N; mid++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				links[i][j] = min(links[i][j], links[i][mid] + links[mid][j]);
			}
		}
	}

	

	int res = 0;
	int minVal = INT_MAX;
	
	for(int i = N; i >= 1; i--){
		int tempVal = 0;
		for(int j = 1; j <= N; j++){
			if(i == j){
				continue;
			}
			tempVal += links[i][j];
		}
		if(tempVal <= minVal){
			minVal = tempVal;
			res = i;
		}
	}

	cout << res;

	return 0;
}