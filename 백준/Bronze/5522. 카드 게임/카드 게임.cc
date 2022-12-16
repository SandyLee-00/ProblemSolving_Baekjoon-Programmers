// 8394번 악수
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*

*/

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int res = 0;
	for(int i = 0; i < 5; i++){
		int a; cin >> a;
		res += a;
	}
	cout << res;
	
	return 0;
}