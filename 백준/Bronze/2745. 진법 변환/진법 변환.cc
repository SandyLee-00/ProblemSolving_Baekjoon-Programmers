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

	string B;
	cin >> B;
	int N;
	cin >> N;

	int res = 0;
	int count = 1;
	int value = 1;

	for(int i = B.size() - 1; i >= 0; i--){
		char tmp = B[i];
		
		if(tmp >= 'A' && tmp <= 'Z'){
			tmp -= 'A';
			tmp += 10;
		}
			
		else{
			tmp -= '0';
		}
		
		res += tmp * value;
		
		value *= N;
		
	}
	cout << res;
	
	return 0;
}