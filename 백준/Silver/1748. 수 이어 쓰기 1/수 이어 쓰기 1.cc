// 1748번 수 이어 쓰기 1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <queue>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	long long res = 0;

	for(int i = 1; i <= N; i *= 10){
		res += N;
		res = res - i + 1;
	}
	
	cout << res;
	
	return 0;
}