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

int answer = 0;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<string> numsStr(3, "");
	vector<int> numsInt(3, -1);
	for (int i = 0; i < 3; i++)
	{
		string str;
		cin >> str;
		numsStr[i] = str;
		
		if (str[0] >= '0' && str[0] <= '9')
		{
			answer = stoi(str);
			answer -= i;
			answer += 3;
			break;
		}
	}

	if (answer % 3 == 0 && answer % 5 == 0)
	{
		cout << "FizzBuzz";
	}
	else if (answer % 3 == 0)
	{
		cout << "Fizz";
	}
	else if (answer % 5 == 0)
	{
		cout << "Buzz";
	}
	else
	{
		cout << answer;
	}


	return 0;
}