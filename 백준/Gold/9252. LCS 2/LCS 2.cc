// 9252번 LCS 2
/*
스트링 입력
배열에서 일치하면 크게 테이블 만들기
변화하는 문자 찾아서 결과 추가하기

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

int dp[1005][1005];

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str1, str2;
	cin >> str1 >> str2;

	str1 = '0' + str1;
	str2 = '1' + str2;

	for (int i = 0; i < 1005; i++) {
		for (int j = 0; j < 1005; j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i < str1.size(); i++) {
		for (int j = 1; j < str2.size(); j++) {
			if (str1[i] == str2[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}


	string resStr;
	int res = 0;
	int pi = str1.size() - 1;
	int pj = str2.size() - 1;

	while (1) {

		if(dp[pi][pj] == 0){
			break;
		}

		if (dp[pi][pj] == dp[pi - 1][pj]) {
			pi -= 1;
		}
		else if (dp[pi][pj] == dp[pi][pj - 1]) {
			pj -= 1;
		}
		else if (dp[pi][pj] != dp[pi][pj - 1] && dp[pi][pj] != dp[pi - 1][pj]) {
			resStr += str1[pi];
			pi -= 1;
			pj -= 1;
			res += 1;
		}
	}

	cout << res << "\n";
	reverse(resStr.begin(), resStr.end());
	if(res != 0){
		cout << resStr;

	}

	return 0;
}