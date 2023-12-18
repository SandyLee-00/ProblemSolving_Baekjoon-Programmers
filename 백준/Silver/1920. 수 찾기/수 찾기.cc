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

vector<int> v;

int biSearch(int target){

	int start = 0;
	int end = v.size()-1;
	int pos = (start + end) / 2;

	while(1){
		// cout << target << " " << pos << "\n";
		pos = (start + end) / 2;

		if(v[pos] == target){
			return 1;
		}

		if(end <= start){
			return 0;
		}

		if(v[pos] > target){
			end = pos;
		}
		else if(v[pos] < target){
			start = pos + 1;
		}
		
	}
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int M;
	cin >> M;
	for(int i = 0; i < M; i++){
		int b;
		cin >> b;

		cout << biSearch(b) << "\n";
	}
	
	return 0;
}