// 1927번 최소 힙
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> h;
	
	int N; cin >> N;
	
	while(N--){
		int x; cin >> x;
		if(x > 0){
			h.push(x);
		}
		else if(x == 0){
			// 비어있으면 0 출력
			if(h.empty()) cout << 0 << "\n";
			else{
				// 가장 작은 값 출력
				// 값 제거
				cout << h.top() << "\n";
				h.pop();
			}
			
			
		}
	}
	
	return 0;
}