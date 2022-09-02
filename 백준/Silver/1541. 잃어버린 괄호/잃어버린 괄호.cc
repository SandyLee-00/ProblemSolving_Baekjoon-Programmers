// 1541번 잃어버린 괄호
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
	
	string input; cin >> input;
	string tmp_s = "";
	bool flag_m = false;
	int res = 0;
	int tmp_i = 0;

	for(int i = 0; i < input.size(); i++){
		char c = input[i];
		// 숫자 
		if(c >= '0' && c <= '9'){
			tmp_s += c;
		}
		// +
		if(c == '+'){
			if(flag_m == false){
				res += stoi(tmp_s);
				tmp_s = "";
				//cout << res << "\n";
			}
			else{
				res -= stoi(tmp_s);
				tmp_s = "";
				//cout << res << "\n";
			}
		}
		// - 
		if(c == '-'){
			if(flag_m == false){
				res += stoi(tmp_s);
				tmp_s = "";
				//cout << res << "\n";
			}
			else{
				res -= stoi(tmp_s);
				tmp_s = "";
				//cout << res << "\n";
			}
			flag_m = true;
		}
		if(i == input.size() - 1){
			
			//cout << "tmp_s : " << tmp_s;
			
			if(flag_m == false){
				res += stoi(tmp_s);
			}
			else{
				res -= stoi(tmp_s);
			}
		}
	}
	
	cout << res;
	
	return 0;
}