#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

/*
이진트리 만들기, 데이터 넣기, 후위순회 출력X
전위 : l m r
후위 : l r m

벡터로 만들기 탐색범위 넘기기 
	*/

vector<int> v;

void rec(int starti, int endi){
	int middle = v[starti];

	if(starti == endi){
		cout << middle << "\n";
		return;
	}

	int rightidx = -1;
	
	for(int i = starti + 1; i <= endi; i++){
		if(v[i] > middle){
			rightidx = i;
			break;
		}
	}

	if(rightidx == -1){
		rec(starti + 1, endi);
	}
	else if(rightidx == starti+1){
		rec(rightidx, endi);
	}
	else{
		rec(starti + 1, rightidx - 1);
		rec(rightidx, endi);
	}
	cout << middle << "\n";
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a;

	while(cin >> a){
		v.push_back(a);
	}
	rec(0, v.size() - 1);

	return 0;
}