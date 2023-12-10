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
	int k;
	cin >> k;

	vector<int> v;

	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end(), greater<int>());

	cout << v[k-1];
	

	return 0;
}
