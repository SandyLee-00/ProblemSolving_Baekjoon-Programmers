// 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*

*/
int cows[100];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int res = 0;

	for(int i = 0; i < 100; i++){
		cows[i] = -1;
	}
	
	for(int i = 0; i < N; i++){
		int cow; cin >> cow;
		int pos; cin >> pos;

		if(cows[cow] != -1 && pos != cows[cow]){
			res ++;
		}
		cows[cow] = pos;
	}
	cout << res;
	
	return 0;
}