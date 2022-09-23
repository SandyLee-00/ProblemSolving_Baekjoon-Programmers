// 1717번 집합의 표현
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

vector<int> p;

int find_(int x){
	if(x == p[x]) return x;
	else{
		int p_x = find_(p[x]);
		p[x] = p_x;
		return p_x;
	}
}

void union_(int a, int b){
	int a_p = find_(a);
	int b_p = find_(b);
	if(a_p == b_p) return;
	else{
		p[b_p] = a_p;
		return;
	}
}

void prt(){
	for(int i = 0; i < p.size(); i++){
		cout << p[i] << " ";
	}
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;

	for(int i = 0; i <= n; i++){
		p.push_back(i);
	}
	// prt();
	while(m--){
		int op, a, b; cin >> op >> a >> b;
		if(op == 0){
			union_(a, b);
		}
		else if(op == 1){
			a = find_(a);
			b = find_(b);
			
			if(a == b) cout << "YES\n";
			else cout << "NO\n";			
		}
		// prt();		
	}
	
	return 0;
}