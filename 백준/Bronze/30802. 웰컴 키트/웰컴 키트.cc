#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <utility>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> sizes(6, 0);
	for (int i = 0; i < 6; i++)
	{
		cin >> sizes[i];
	}

	int T, P;
	cin >> T >> P;

	int ans1 = 0, ans2 = 0, ans3 = 0;
	for (int i = 0; i < 6; i++)
	{
		int count = sizes[i] / T;
		if (sizes[i] % T != 0)
		{
			count += 1;
		}
		
		ans1 += count;
	}

	ans2 = N / P;
	ans3 = N % P;

	cout << ans1 << "\n" << ans2 << " " << ans3;



	return 0;
}