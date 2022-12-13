// 13335번 트럭
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*

*/

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T; cin >> T;
	while(T--){
		string a, b; cin >> a >> b;
		int aCnt[50];
		int bCnt[50];
		
		for(int i = 0; i < 50; i++){
			aCnt[i] = 0;
			bCnt[i] = 0;
		}
		
		for(int i = 0; i < a.size(); i++){
			char aL = a[i] - 'a';
			aCnt[aL]++;
			char bL = b[i] - 'a';
			bCnt[bL]++;
		}

		string res = " are anagrams.\n";
		if(a.size() != b.size())
			res = " are NOT anagrams.\n";
		
		for(int i = 0; i < 50; i++){
			if(aCnt[i] != bCnt[i]){
				res = " are NOT anagrams.\n";
			}
		}
		cout << a << " & " << b << res;
	}
	
	return 0;
}