// 1967번 트리의 지름
/*
트리 상태 Node tree[10005]로 표현하기
Node에 parent pWeight children cWeights 넣기 X

1에서 DFS -> 가장 긴 부분 점
긴 점 DFS -> 다른 부분 점

트리 구조에서 벗어나서 생각해야했다 그래프 이다
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <sstream>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

struct Node {
	vector<int> nextNodes;
	vector<int> nWeights;
};

Node trees[10005];
bool visited[10005];
int maxNode = 0;
int maxValue = 0;

void DFS(int node, int sum) {
	if (sum >= maxValue) {
		maxValue = sum;
		maxNode = node;
	}

	for (int i = 0; i < trees[node].nextNodes.size(); i++) {
		int nextNode = trees[node].nextNodes[i];
		if(visited[nextNode] == false){
			visited[nextNode] = true;
			DFS(nextNode, sum + trees[node].nWeights[i]);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		trees[a].nextNodes.push_back(b);
		trees[a].nWeights.push_back(c);

		trees[b].nextNodes.push_back(a);
		trees[b].nWeights.push_back(c);
	}

	visited[1] = true;
	DFS(1, 0);

	for(int i = 0; i < 10005; i++){
		visited[i] = false;
	}
	visited[maxNode] = true;
	DFS(maxNode, 0);

	cout << maxValue;

	return 0;
}