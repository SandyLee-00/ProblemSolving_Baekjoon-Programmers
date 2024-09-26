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

/*
1~9 배열에 개수 넣기
꼬치 투포인터로 맨 앞, 뒤에서 하나씩 빼기
남은 개수 더 적은 종류 빼기 X 범위 안에서 최대 길이 구해야 했다

투포인터 끝까지 가면서 종류2개 이하 되게 카운팅 하기
*/

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	int lidx = 0;
	int ridx = 0;
	int answer = 1;
	vector<int> counts(10, 0);

	counts[v[0]] = 1;

	while (1)
	{
		if (ridx == v.size() - 1) break;

		// 앞 칸 하나 포함
		// 두 종류 이상이면 뒤에꺼 당기기 
		ridx += 1;
		counts[v[ridx]] += 1;

		int kind = 0;
		for (int i = 0; i < 10; i++)
		{
			if (counts[i] > 0)
			{
				kind += 1;
			}
		}
		if (kind > 2)
		{
			counts[v[lidx]] -= 1;
			lidx += 1;
		}
		
		answer = max(answer, ridx - lidx + 1);
	}

	cout << answer;

	return 0;
}