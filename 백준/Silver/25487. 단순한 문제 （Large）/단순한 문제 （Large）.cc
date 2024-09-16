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

	int T;
	cin >> T;
	while(T--){
		int a, b, c;
		cin >> a >> b >> c;

		int answer = min(a, b);
		answer = min(answer, c);
		

		cout << answer << "\n";
	}
	

	return 0;
}