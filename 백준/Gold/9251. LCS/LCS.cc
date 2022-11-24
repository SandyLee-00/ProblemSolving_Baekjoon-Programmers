// 9251번 LCS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
1 str1 str2 입력
2 dp -1 초기화
3 res 구하기

3 

*/
string str1, str2;
int str1Size, str2Size;
int dp[1005][1005];

int sol(int str1Idx, int str2Idx){
	if(str1Idx == -1 || str2Idx == -1) return 0;
	
	int& ret = dp[str1Idx][str2Idx];
	if(ret != -1) return ret;

	
	
	if(str1[str1Idx] == str2[str2Idx]){
		ret = 1 + sol(str1Idx-1, str2Idx-1);
	}
	else{
		ret = max(sol(str1Idx-1, str2Idx), sol(str1Idx, str2Idx-1));
	}

	return ret;
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> str1 >> str2;
	
	for(int i = 0; i < 1005; i++){
		for(int j = 0; j < 1005; j++){
			dp[i][j] = -1;
		}
	}
	str1Size = str1.size();
	str2Size = str2.size();
	int res = sol(str1Size-1, str2Size-1);
	
	for(int i = 0; i < str1Size; i++){
		for(int j = 0; j < str2Size; j++){
			// cout << dp[i][j] << " ";
		}
		// cout << "\n";
	}
	
	cout << res;
	
	return 0;
}