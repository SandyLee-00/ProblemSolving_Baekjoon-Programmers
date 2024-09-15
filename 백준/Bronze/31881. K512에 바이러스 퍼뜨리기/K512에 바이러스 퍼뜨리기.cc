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
#include <map>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, Q;
	cin >> N >> Q;
	int sum = N;

	vector<int> vec(N+1, 0);
	
	for(int i = 0; i < Q; i++){
		int a;
		cin >> a;
		if(a == 1){
			int b;
			cin >> b;
			if(vec[b] == 0){
				sum -= 1;
			}
			
			vec[b] = 1;
		}
		if(a == 2){
			int b;
			cin >> b;
			if(vec[b] == 1){
				sum += 1;
			}

			vec[b] = 0;
		}
		if(a == 3){
			
			cout << sum << "\n";
		}
		
	}

	
	
	

	return 0;
}