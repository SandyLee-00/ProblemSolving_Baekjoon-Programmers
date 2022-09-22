// 2504번 괄호의 값
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	double tmp = 1;
	long long res = 0;
	string str; cin >> str;

	for(int i = 0; i < str.size(); i++){
		if(str[i] == '('){
			tmp *= 2;
			if(str[i+1] == ')'){
				res += tmp;
			}
		}
		else if(str[i] == ')'){
			tmp /= 2;
			if(tmp < 1){
				res = 0;
				break;
			}
		}
		else if(str[i] == '['){
			tmp *= 3;
			if(str[i+1] == ']'){
				res += tmp;
			}
		}
		else if(str[i] == ']'){
			tmp /= 3;
			if(tmp < 1){
				res = 0;
				break;
			}
		}
		else{
			res = 0;
			break;
		}
		// cout << tmp << " ";
	}
	if(tmp == 1)cout << res;
	else cout << 0;
	
	return 0;
}