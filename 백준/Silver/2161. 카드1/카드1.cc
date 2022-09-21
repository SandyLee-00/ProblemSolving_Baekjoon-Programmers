// 2161번 카드1
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

	queue<int> q;
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		q.push(i);
	}
	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
		if(!q.empty()){
			int a = q.front();
			q.pop();
			q.push(a);
		}
		
	}
	
	return 0;
}