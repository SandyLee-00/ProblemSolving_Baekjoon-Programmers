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
최대공약수 구하기
최소공배수 구하기
두 숫자 중 큰 수 찾기
큰 숫자 기준으로 0 1 ~ 곱해서 최소공배수까지 체크
*/

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while(T--){
		int M, N;
		cin >> M >> N;

		int x, y;
		cin >> x >> y;

		int tempM = M;
		int tempN = N;
		while(1){
			if(tempN == 0){
				break;
			}
			int r = tempM % tempN;
			tempM = tempN;
			tempN = r;
		}
		int gcd = tempM;
		long long lcm = M * N / gcd;

		if(M < N){
			int tmp = M;
			M = N;
			N = tmp;

			int tmp2 = x;
			x = y;
			y = tmp2;
		}

		int cnt = 0;
		while(1){
			if(M * cnt > lcm){
				cout << -1 << "\n";
				break;
			}

			int resMaybe = M * cnt + x - 1;
			if(resMaybe % N == y - 1){
				cout << resMaybe + 1 << "\n";
				break;
			}
			else{
				cnt++;
			}
		}
		
	}

	return 0;
}