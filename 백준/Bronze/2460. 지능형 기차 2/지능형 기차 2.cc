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

	int count = 0;
	int resMax = INT_MIN;
	
	for(int i = 0; i < 10; i++){
		int fir, sec;
		cin >> fir >> sec;

		count += sec;
		count -= fir;

		resMax = max(resMax, count);
	}

	cout << resMax;
	
	return 0;
}