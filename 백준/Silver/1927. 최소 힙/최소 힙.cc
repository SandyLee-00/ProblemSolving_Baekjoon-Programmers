// 
/*

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
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i = 0; i < N; i++){
		int a;
		cin >> a;

		if(a == 0){
			if(!pq.empty()){
				cout << pq.top() << "\n";
				pq.pop();
			}
			else{
				cout << 0 << "\n";
			}
			
		}
		else{
			pq.push(a);
		}
	}
	

	return 0;
}
