// 2903번 중앙 이동 알고리즘
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <deque>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int res = 3;
	for(int i = 1; i < N; i++){
		res = (res - 1) * 2 + 1;
	}
	res = res * res;
	cout << res;
	
	return 0;
}