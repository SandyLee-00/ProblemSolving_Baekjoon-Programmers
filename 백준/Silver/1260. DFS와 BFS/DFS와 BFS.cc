// 1260번 DFS와 BFS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
using namespace std;

const int MAX = 1001;

int grp[MAX][MAX];
int visited[MAX];
queue<int> store;

int nodeNum, edgeNum, startNode;

void DFS(int node){
	visited[node] = 1;
	cout << node << " ";
	
	for(int i = 1; i <= nodeNum; i++){
		if(grp[node][i] == 1 && visited[i] == 0){
			DFS(i);
		}
	}
}

void BFS(int node){
	store.push(node);
	visited[node] = 1;
	cout << node << ' ';

	while(!store.empty()){
		int tempn = store.front();
		store.pop();
		
		for(int i = 1; i <= nodeNum; i++){			
			if(grp[tempn][i] == 1 && visited[i] == 0){
				store.push(i);
				visited[i] = 1;
				cout << i << ' ';
			}
		}
	}
}

void reset(){
	for(int i = 0; i < MAX; i++){
		visited[i] = 0;
		//cout << "reset : " << i << ' ';
	}
}

int main(){
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> nodeNum >> edgeNum >> startNode;

	for(int i = 0; i < edgeNum; i++){
		int a, b;
		cin >> a >> b;
		grp[a][b] = 1;
		grp[b][a] = 1;
	}
	
	reset();
	DFS(startNode);
	cout << "\n";
	reset();

	BFS(startNode);
	cout << "\n";
	
	return 0;
}