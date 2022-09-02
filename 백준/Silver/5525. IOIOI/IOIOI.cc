// 5525번 IOIOI
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int Pn; cin >> Pn;
	int S_len; cin >> S_len;
	string S; cin >> S;
	int res = 0;
	
	for(int i = 0; i < S.length() - 2; i++){
		int ioCnt = 0;
		if(S[i] == 'O') continue;
		while(S[i] == 'I' && S[i + 1] == 'O'&& S[i + 2] == 'I'){
			ioCnt += 1;
			i += 2;
			if(ioCnt == Pn){
				ioCnt -= 1;
				res += 1;
			}
		}
	}
	cout << res;
	
	return 0;
}