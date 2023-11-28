// 1753번 최단경로
/*
시작 노드와 연결된 노드 거리 비교해서 업데이트
시작 노드 방문 체크

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <set>
#include <sstream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	cin.ignore();
	
	while(t--){
		string str;
		getline(cin, str);

		int size = str.size();
		stack<int> s;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == ' '){
				while(!s.empty()){
					cout << char(s.top());
					s.pop();
				}
				cout << " ";
			}
			else{
				s.push(str[i]);
			}
		}
		while(!s.empty()){
			cout << char(s.top());
			s.pop();
		}
		cout << " ";
		cout << "\n";
	}
	
	return 0;
}