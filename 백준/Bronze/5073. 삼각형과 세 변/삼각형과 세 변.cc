// 
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
 
*/

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while(1){
		int a, b, c;
		string res = "Scalene";
		cin >> a >> b >> c;
		if(a == 0 && b == 0 && c == 0){
			break;
		}
		if(a == b && a == c){
			res = "Equilateral";
		}
		else if(a == b || b == c || a == c){
			res = "Isosceles";
		}
		int maxL = max(a, b);
		maxL = max(maxL, c);
		if(maxL >= a + b || maxL >= a + c || maxL >= b + c){
			res = "Invalid";
		}
		cout << res << "\n";
	}
	
	
	return 0;
}