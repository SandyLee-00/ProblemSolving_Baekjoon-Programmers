// 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <climits>
using namespace std;

/*

*/

bool isContain666(int num)
{
	string tmp = to_string(num);
	if(tmp.find("666") != string::npos)
	{
		return true;
	}
	return false;
}


int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> vec;
	
	for(int num = 500; num < 9999999; num++)
	{
		// cout << num;
		if(isContain666(num) == true)
		{
			vec.push_back(num);
		}
	}

	for(int i = 0; i < vec.size(); i++)
		{
			// cout << vec[i] << " ";
		}

	cout << vec[N-1];

	return 0;
}