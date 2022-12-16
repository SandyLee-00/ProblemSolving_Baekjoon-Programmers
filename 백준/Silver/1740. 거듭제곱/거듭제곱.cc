// 1740번 거듭제곱
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
1 N 2진수로 변환
2 변환한 이진수 거꾸로 뒤집기
3 하나씩 인덱스로 읽으면서 값 더하기

*/

vector<ll> threes;
void makeThrees(){
	ll num = 1;
	for(int i = 0; i < 40; i++){
		threes.push_back(num);
		num *= 3;
	}
}
string to_Binary(ll N){
	string ret = "";
	while(1){
		if(N == 0) break;
		if(N % 2 == 0){
			ret += "0";
			N /= 2;
		} 
		else {
			ret += "1";
			N /= 2;
		}
	}
	return ret;
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll N; cin >> N;
	makeThrees();
	string NtoBinary = to_Binary(N);

	ll res = 0;
	for(int i = 0; i < NtoBinary.size(); i++){
		int val = NtoBinary[i] - '0';
		if(val){
		res += threes[i];
		}
	}
	cout << res;
	
	return 0;
}