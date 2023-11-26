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


	for(int i = 0; i < M; i++){
		int fir, sec, third;
		cin >> fir >> sec >> third;
		for(int j = fir; j <= sec; j++){
			v[j] = third;
		}
	}

	for(int i = 1; i <= N; i++){
		cout << v[i] << " ";
	}
	
	return 0;
}