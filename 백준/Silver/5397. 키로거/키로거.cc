#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	while(T--){
		string str; cin >> str;
		stack<char> s1, s2;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == '-'){
				if(s1.size() > 0){
					s1.pop();
				}
			}
			else if(str[i] == '<'){
				if(s1.size() > 0){
					char a = s1.top();
					s1.pop();
					s2.push(a);
				}
			}
			else if(str[i] == '>'){
				if(s2.size() > 0){
					char a = s2.top();
					s2.pop();
					s1.push(a);
				}
			}
			else{
				s1.push(str[i]);
			}
		}
		stack<char>res;
		while(!s1.empty()){
			res.push(s1.top()); 
			s1.pop();
		}
		while(!res.empty()){
			cout << res.top();
			res.pop();
		}
		while(!s2.empty()){
			cout << s2.top();
			s2.pop();
		}
		cout << "\n";
	}
	
	return 0;
}