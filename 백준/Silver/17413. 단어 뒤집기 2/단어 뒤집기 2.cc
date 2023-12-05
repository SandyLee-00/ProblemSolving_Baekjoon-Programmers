// 
/*


*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <set>
#include <sstream>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str, res;
	getline(cin, str);

	stack<char> s;
	stack<char> ts;
	bool isTag = false;

	for(int i = 0; i < str.size(); i++){
		char a = str[i];
		
		if(a == '<'){
			while(!s.empty()){
				res += s.top();
				s.pop();
			}
			isTag = true;
			
			s.push(a);
		}
			
		else if(a == '>'){
			isTag = false;
			
			while(!s.empty()){
				ts.push(s.top());
				s.pop();
			}

			while(!ts.empty()){
				res += ts.top();
				ts.pop();
			}
			res += '>';
		}
			
		else if(isTag == true){
			s.push(a);
		}
			
		else if(a == ' ' && isTag == false){
			while(!s.empty()){
				res += s.top();
				s.pop();
			}
			res += ' ';
		}
			
		else if(isTag == false){
			s.push(a);
		}
	}

	while(!s.empty()){
		res += s.top();
		s.pop();
	}
	
	cout << res;
	
	return 0;
}