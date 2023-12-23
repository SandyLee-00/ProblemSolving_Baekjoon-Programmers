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
#include <sstream>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int nums[10005];

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		nums[a] += 1;
	}

	for(int i = 1; i < 10005; i++){
		int j = nums[i];
		if(nums[i] >= 0){
			for(j; j > 0; j--){
				cout << i << "\n";
			}
		}
	}
	
	
	return 0;
}