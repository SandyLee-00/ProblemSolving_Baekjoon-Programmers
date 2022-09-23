// 1976번 여행 가자
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
		int x_p = find_(p[x]);
		p[x] = x_p;
		return x_p;
	}
}

void union_(int a, int b){
	int a_p = find_(a);
	int b_p = find_(b);
	if(a_p == b_p) return;
	else{
		p[b_p] = a_p;
	}
}

void prt(){
	for(int i = 0; i < p.size(); i++){
		cout << p[i] << " ";
	}
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	
	int N, M; cin >> N >> M;

	for(int i = 0; i <= N; i++){
		p.push_back(i);
	}
		
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			int con; cin >> con;
			if(con == 1){			
				union_(i, j);
			}
		}
	}
	int fir; cin >> fir;
	int p_fir = find_(fir);
	M -= 1;;
	
	string res = "YES";
	
	while(M--){
		int x; cin >> x;
		int p = find_(x);
		
		if(p != p_fir){
			res = "NO";
			break;
		}
	}
	cout << res;
	
	return 0;
}
