// 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
using ll = long long;

/*

*/

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> nums(n, 0);

	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());

	float delSizeF = (float)n * 0.15;
	int delSize = int(delSizeF);
	if(delSizeF - int(delSizeF) >= 0.5)
		delSize++;

	double sum = 0;
	for(int i = delSize; i < n - delSize; i++){
		sum += nums[i];
		//cout << nums[i] << " ";
	}
	sum /= (n - delSize * 2);
	int sumres = int(sum);
	if(sum - int(sum) >= 0.5)
		sumres++;

	if(n == 0)
		sumres = 0;
	
	cout << sumres;
	
	return 0;
}