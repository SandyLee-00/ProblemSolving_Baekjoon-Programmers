// 1644번 소수의 연속합
/*
MAX 까지 벡터에 소수 넣어놓기
투포인터로 합 만들어지는 것 체크하기
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
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int MAX = 4000005;
vector<int> pnums;
int dp[MAX];

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	pnums.push_back(0);

	for(int i = 2; i < MAX; i++){
		if(dp[i] == 0){
			pnums.push_back(i);
			for(int j = i * 2; j < MAX; j += i){
				dp[j] = 1;
			}
		}
	}

	int startIdx = 0, endIdx = 0;
	int sum = 0, res = 0;
	
	while(1){
		if(endIdx > pnums.size()){
			break;
		}
		if(sum < N){
			sum += pnums[endIdx];
			endIdx += 1;
		}
		else if(sum == N){
			res += 1;
			sum += pnums[endIdx];
			endIdx += 1;
		}
		else if(sum > N){
			sum -= pnums[startIdx];
			startIdx += 1;
		}
	}
	
	cout << res;


	return 0;
}