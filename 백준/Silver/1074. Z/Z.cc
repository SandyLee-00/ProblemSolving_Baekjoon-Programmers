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

int res = 0;

void doRecur(int N, long long row, long long colum){

	if(N == 0) return;
	int div = pow(2, N) / 2;
	int partR = row / div;
	int partC = colum / div;
	if(partR == 0 && partC == 1){
		res += div * div * 1;
	}
	else if(partR == 1 && partC == 0){
		res += div * div * 2;
	}
	else if(partR == 1 && partC == 1){
		res += div * div * 3;
	}
	doRecur(N-1, row % div, colum % div);
}

int main() 
{
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// N r c 입력받기
	int N;
	long long r;
	long long c;
	cin >> N >> r >> c;
	
	// 재귀호출로 res 누적해서 더하기 
	doRecur(N, r, c);
	// 4* 0 1 2 3
	// depth 0 일 때까지 하기

	cout << res;
	
	return 0;
}