// 11279번 최대 힙
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	priority_queue<int>pq;
	int N; cin >> N;
	while(N--){
		int n; cin >> n;
		if(n == 0){
			if(pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else if(n != 0){
			pq.push(n);
		}
	}
	
	return 0;
}