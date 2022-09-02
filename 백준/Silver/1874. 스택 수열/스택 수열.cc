// 1874번 스택 수열
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <deque>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;

	stack<int> s;
	string res = "";

	int cnt = 0;
	for(int i = 0; i < n; i++){
		int innum; cin >> innum;
		// cout << "innum : " << innum << "\n";
		while(innum > cnt){
			cnt += 1;
			s.push(cnt);
			res += "+\n";
			// cout << "push cnt :" << cnt << "\n";
		}
		if(s.top() == innum){
			s.pop();
			res += "-\n";
			// cout << "pop innum :" << innum << "\n";
		}
		if(!s.empty()){
			if(s.top() > innum){
				res = "NO";
				break;
			}
		}
	}
	
	cout << res;
	
	return 0;
}