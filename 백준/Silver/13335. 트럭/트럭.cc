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

	int n, w, L;
	cin >> n >> w >> L;

	queue<int> trucks;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		trucks.push(a);
	}

	int res = 0;
	int weight = 0;
	queue<pair<int, int>> bridge;
	queue<pair<int, int>> tq;
	
	while(!trucks.empty() || !bridge.empty()){
		res++;

		if(!trucks.empty() && weight + trucks.front() <= L){
			bridge.push({trucks.front(), w});
			weight += trucks.front();
			trucks.pop();
		}

		while(!bridge.empty()){
			int val = bridge.front().second - 1;
			if(val > 0){
				tq.push({bridge.front().first, val});
			}
			else{
				weight -= bridge.front().first;
			}
			bridge.pop();
		}

		while(!tq.empty()){
			bridge.push({tq.front().first, tq.front().second});
			tq.pop();
		}
	}
	cout << res + 1;
	
	return 0;
}