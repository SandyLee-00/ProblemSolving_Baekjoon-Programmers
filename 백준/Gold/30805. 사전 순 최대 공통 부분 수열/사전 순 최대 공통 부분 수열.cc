#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
#include <limits.h>
using namespace std;
using ll = long long;

/*

*/

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> v1;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v1.push_back(a);
	}

	int M;
	cin >> M;

	vector<int> v2;
	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		v2.push_back(a);
	}

	vector<int> answers;

	int start1 = -1;
	int start2 = -1;
	for (int k = 0; k < v1.size(); k++)
	{
		int maxValue = 0;
		int tmp1 = 0;
		int tmp2 = 0;

		for (int i = start1 + 1; i < v1.size(); i++)
		{
			for (int j = start2 + 1; j < v2.size(); j++)
			{
				if (v1[i] == v2[j])
				{
					if (v1[i] > maxValue)
					{
						maxValue = v1[i];
						tmp1 = i;
						tmp2 = j;

						// cout << maxValue << " ";
					}
				}
			}
		}

		if(maxValue != 0)
		{
			start1 = tmp1;
			start2 = tmp2;
			answers.push_back(maxValue);
		}
	}

	if(answers.size() == 0)
	{
		cout << 0;
	}
	else{

		cout << answers.size() << "\n";

		for(int i = 0; i < answers.size(); i++)
		{
			cout << answers[i] << " ";
		}
	}

	return 0;
}