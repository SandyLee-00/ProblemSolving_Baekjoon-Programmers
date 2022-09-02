// 1759번 암호 만들기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
using namespace std;

int L;
int C;
vector<int> vis;
vector<int> res;
vector<char> alphbet;
int cnt = 0;
int cnt_aeiou = 0;
int cnt_others = 0;

void DFS(int now, int cnt, int cnt_aeiou, int cnt_others){
	
	if(cnt == L && cnt_aeiou >= 1 && cnt_others >= 2){
		// 개수 되면 출력
		for(int i = 0; i < C; i++){
			if(vis[i] == 1){
				cout << alphbet[i];
			}
		}
		cout << "\n";
		
		return;
	}
	for(int i = now; i < C; i++){
		if(vis[i] == 0){
			cnt += 1;
			vis[i] = 1;
			if(alphbet[i] == 'a' || alphbet[i] == 'e' || alphbet[i] == 'i' || alphbet[i] == 'o' || alphbet[i] == 'u'){
				cnt_aeiou += 1;
			}
			else cnt_others += 1;
			DFS(i, cnt, cnt_aeiou, cnt_others);
			if(alphbet[i] == 'a' || alphbet[i] == 'e' || alphbet[i] == 'i' || alphbet[i] == 'o' || alphbet[i] == 'u'){
				cnt_aeiou -= 1;
			}
			else cnt_others -= 1;
			vis[i] = 0;
			cnt -= 1;
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> L;
	cin >> C;

	for(int i = 0; i < C; i++){
		char a;
		cin >> a;
		alphbet.push_back(a);
	}
	for(int i = 0; i < C; i++){
		vis.push_back(0);
	}
	for(int i = 0; i < L; i++){
		res.push_back(0);
	}
	
	sort(alphbet.begin(), alphbet.end());
	
	DFS(0, 0, 0, 0);
	
	return 0;
}