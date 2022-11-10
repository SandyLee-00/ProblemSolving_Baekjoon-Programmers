// 1406번 에디터
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str; cin >> str;
	int M; cin >> M;
	list<char> li;
	
	int str_size = str.size();
	for(int i = 0; i < str_size; i++){
		li.push_back(str[i]);
	}
	
	auto iter = li.end();
	
	for(int i = 0; i < M; i++){
		char command; cin >> command;
		if(command == 'L' && iter != li.begin()){
			iter--;
		}
		else if(command == 'D' && iter != li.end()){
			iter++;
		}
		else if(command == 'B' && li.begin() != li.end() && iter != li.begin()){
			--iter;
			iter = li.erase(iter);
		}
		else if(command == 'P'){
			char a; cin >> a;
			li.insert(iter, a);
		}
		
	}
	
	for(iter = li.begin(); iter != li.end(); iter++){
		cout << *iter;
	}
	
	return 0;
}