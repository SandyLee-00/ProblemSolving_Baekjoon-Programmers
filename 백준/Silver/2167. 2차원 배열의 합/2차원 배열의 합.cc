//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
using ll = long long;

/*


*/

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> vec(N, vector<int>(M));
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> vec[i][j];
		}
	}

	int K;
	cin >> K;
	
	for(int i = 0; i < K; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int sum = 0;

		for(int j = a - 1; j < c; j++){
			for(int k = b - 1; k < d; k++){
				sum += vec[j][k];
			}
		}

		cout << sum << "\n";
	}
	
	return 0;
}