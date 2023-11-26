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

	int N, F;
	cin >> N >> F;

	string str = to_string(N);

	int size = str.size();

	for(int i = 0; i <= 9; i++){
		for(int j = 0; j <= 9; j++){
			str[size-2] = i + '0';
			str[size-1] = j + '0';

			if(stoi(str) % F == 0){
				cout << i << j;
				return 0;
			}
		}
	}
	
	return 0;
}