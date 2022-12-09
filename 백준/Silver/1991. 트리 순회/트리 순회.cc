// 1991번 트리 순회
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
1 node data l r 구조 만들기
2 데이터 입력, 연결상태 만들기
3 전위
4 중위
5 후위
*/

map<char, pair<char, char>> tree;

void preorder(char node){
	cout << node << "";
	if(tree[node].first != '.')
		preorder(tree[node].first);
	if(tree[node].second != '.')
		preorder(tree[node].second);
}

void inorder(char node){
	if(tree[node].first != '.')
		inorder(tree[node].first);
	cout << node << "";
	if(tree[node].second != '.')
		inorder(tree[node].second);
}

void postorder(char node){
	if(tree[node].first != '.')
		postorder(tree[node].first);
	if(tree[node].second != '.')
		postorder(tree[node].second);
	cout << node << "";
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	
	while(N--){
		char a, b, c; cin >> a >> b >> c;
		tree[a] = {b, c};
	}
	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	
	return 0;
}