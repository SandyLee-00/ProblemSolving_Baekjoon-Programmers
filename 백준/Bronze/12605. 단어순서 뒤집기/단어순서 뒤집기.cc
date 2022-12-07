//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*

*/

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int T = N;
	cin.ignore();
	while(T--){
		string str;
		getline(cin, str);
		string tmp = "";
		string res = "";
		
		for(int i = 0; i < str.size(); i++){
			if(str[i] == ' '){
				res = tmp + " " + res;
				tmp = "";
				// cout << tmp << " ";
			}
			else{
				tmp += str[i];
			}
		}
		res = tmp + " "+ res;
		cout << "Case #" << N - T << ": ";
		cout << res << "\n";
	}
	
	
	
	return 0;
}