//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*

*/

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	int res = 0;
	while(T--){
		stack<char> s;
		string str; cin >> str;
		for(int i = 0; i < str.size(); i++){
			if(s.empty()){
				s.push(str[i]);
			}
			else{
				if(s.top() == str[i]){
					s.pop();
				}
				else{
					s.push(str[i]);
				}
			}
		}
		if(s.empty()) res += 1;
	}
	cout << res;
	
	return 0;
}