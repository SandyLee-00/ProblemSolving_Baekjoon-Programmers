// 
/*

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <climits>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> v(N + 1);

	for(int i = 0; i <= N; i++){
		v[i] = i;
	}

	for(int i = 0; i < M; i++){
		int fir, sec;
		cin >> fir >> sec;
		
			int tmp = v[fir];
			v[fir] = v[sec];
			v[sec] = tmp;
	}

	for(int i = 1; i <= N; i++){
		cout << v[i] << " ";
	}
	
	return 0;
}