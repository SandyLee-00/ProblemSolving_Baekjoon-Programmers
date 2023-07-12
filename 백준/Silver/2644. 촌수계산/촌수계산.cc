// 2644번 촌수계산

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
const int SIZE = 105;
bool all[SIZE][SIZE];
bool visNode[SIZE];
int res = -1;

void doDFS(int nowNode, int tarNode2, int cnt){

	if(nowNode == tarNode2){
		res = cnt;
	}
	
	for(int i = 0; i < SIZE; i++){
		if(all[nowNode][i] == true && visNode[i] == false){
			cnt++;
			visNode[i] = true;
			// cout << i << " / " << tarNode2 << " / " << cnt << "\n";
			doDFS(i, tarNode2, cnt);
			cnt--;
			visNode[i] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	int tarNode1, tarNode2;
	cin >> tarNode1 >> tarNode2;

	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		all[a][b] = true;
		all[b][a] = true;
	}

	doDFS(tarNode1, tarNode2, 0);
	cout << res;
	
	return 0;
}