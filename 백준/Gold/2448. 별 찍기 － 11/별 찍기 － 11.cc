#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
using namespace std;

/*

*/

char m[4000][7000];

void PrintStar(int N, int posi, int posj)
{
	if(N == 3)
	{
		m[posi][posj] = '*';

		m[posi+1][posj-1] = '*';
		m[posi+1][posj+1] = '*';

		m[posi+2][posj-2] = '*';
		m[posi+2][posj-1] = '*';
		m[posi+2][posj] = '*';
		m[posi+2][posj+1] = '*';
		m[posi+2][posj+2] = '*';


		return;
	}

	PrintStar(N / 2, posi, posj);
	PrintStar(N / 2, posi + N/2, posj - N / 2);
	PrintStar(N / 2, posi + N/2, posj + N / 2);

}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for(int i = 0; i < 4000; i++)
	{
		for(int j = 0; j < 7000; j++)
		{
			m[i][j] = ' ';
		}
	}

	PrintStar(N, 0, N-1);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N * 2; j++)
		{
			cout << m[i][j];
		}
		cout << "\n";
	}

	return 0;
}