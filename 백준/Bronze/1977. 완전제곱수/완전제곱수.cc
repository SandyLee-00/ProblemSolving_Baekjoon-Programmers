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

	int M, N;
	cin >> M >> N;

	ll sum = 0;
	int min = -1;
	for(int i = 0; i < 102; i++){
		int iSquare = i * i;
		if(iSquare >= M && iSquare <= N){
			sum += iSquare;
			if(min == -1){
				min = iSquare;
			}
		}
	}
	if(min == -1){
		cout << -1;
		return 0;
	}

	cout << sum << "\n" << min;
	
	return 0;
}