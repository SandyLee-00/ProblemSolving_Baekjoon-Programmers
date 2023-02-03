// 2407번 조합
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
파스칼 삼각형
재귀로 계속 더하기
문자열 큰 수 더하기

큰 수 덧셈에서 int 범위를 벗어나면 값이 이상해진다
왜 그런지 모르겠다.

*/

string add(string str1, string str2){
	string str = "";
	int minSize = min(str1.size(), str2.size());
	int carry = 0;
	
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	
	for(int i = 0; i < minSize; i++){
		int digit = str1[i]-'0' + str2[i]-'0' + carry;
		carry = 0;
		
		if(digit >= 10){
			carry = 1;
			digit -= 10;
		}
		char digitC = (digit + '0');
		str += digitC;
	}
	if(str1.size() > minSize){
		for(int i = minSize; i < str1.size(); i++){
			int digit = str1[i]-'0' + carry;
			carry = 0;
		
			if(digit >= 10){
				carry = 1;
				digit -= 10;
			}
			char digitC = (digit + '0');
			str += digitC;
		}
	}
	else if(str2.size() > minSize){
		for(int i = minSize; i < str2.size(); i++){
			int digit = str2[i]-'0' + carry;
			carry = 0;
		
			if(digit >= 10){
				carry = 1;
				digit -= 10;
			}
			char digitC = (digit + '0');
			str += digitC;
		}
	}
	if(carry >= 1){
		str += char(carry+'0');
	}
	
	reverse(str.begin(), str.end());
	return str;
}

string dp[105][105];

string sol(int fir, int sec){
	string & ret = dp[fir][sec];
	if(ret != "")
		return ret;
	
	if(sec == fir || sec == 0)
		return "1";
	
	ret = add(sol(fir-1, sec-1), sol(fir-1, sec));
	// cout << fir << " " << sec << " "<< ret << "\n";
	return ret;
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;
	cout << sol(n, m);
	// cout << add(to_string(n), to_string(m));
	
	return 0;
}