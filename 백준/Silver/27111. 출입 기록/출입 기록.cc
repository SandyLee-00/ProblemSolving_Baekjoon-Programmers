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

	int N;
	cin >> N;

	vector<int> vec(200001, 0);

	int answer = 0;

	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;

		if(vec[a] == 0 && b == 1){
			vec[a] = 1;
			continue;
		}
		if(vec[a] == 1 && b == 0){
			vec[a] = 0;
			continue;
		}

		else{
			vec[a] = b;
			answer += 1;
		}
	}

	for(int i = 0; i < 200001; i++){
		if(vec[i] == 1){
			answer += 1;
		}
	}

	cout << answer;


	return 0;
}