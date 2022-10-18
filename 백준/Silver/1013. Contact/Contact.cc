// 1013번 Contact
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <regex>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	regex re("(100+1+|01)+");
	
	while(T--){
		string str;
		cin >> str;
		int str_size = str.size();

		if(regex_match(str, re)){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
		
	}
	
	return 0;
}