// 9019번 DSLR
#include <bits/stdc++.h>
using namespace std;
/*
D n * 2
S 1234 -> 1233
L 1234 -> 2341
R 1234 -> 4123

큐에 이전까지 문자, 현재 숫자 저장, 계속해서 타겟에 도착할 때까지 하기
bfs(A){
if(num == B) return str
else{
1num
2num
3num
4num
q.push({str + type, tNum})
}
}

*/

int vis[20000];

string bfs(int A, int B){
	queue<pair<string, int>> q;
	q.push({"", A});
	while(1){
		string str = q.front().first;
		int num = q.front().second;
		q.pop();
		if(num == B){
			for(int i = 0; i < 20000; i++){
				vis[i] = 0;
			}
			return str;
		}
		
		int fir = (num * 2) % 10000;
		
		int sec = num - 1;
		if(num == 0) sec = 9999;

		int tmp = num / 1000;
		int thir = (num - tmp*1000) * 10 + tmp;
		tmp = num % 10;
		int four = num / 10 + tmp*1000;

		/*
		cout << num << " ";
		cout << "D: " << fir << " ";
		cout << "S: " << sec << " ";
		cout << "L: " << thir << " ";
		cout << "R: " << four << " ";
		cout << "\n";
		*/
		if(vis[fir] == 0){
			vis[fir] = 1;
			q.push({str + "D", fir});
		}
		if(vis[sec] == 0){
			vis[sec] = 1;
			q.push({str + "S", sec});
		}
		if(vis[thir] == 0){
			vis[thir] = 1;
			q.push({str + "L", thir});
		}
		if(vis[four] == 0){
			vis[four] = 1;
			q.push({str + "R", four});
		}
			
	}
}


int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	while(T--){
		int A; cin >> A;
		int B; cin >> B;
		string res = bfs(A, B);
		cout << res << "\n";
	}
	
	return 0;
}