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

	int N;
	cin >> N;
	stack<int> s;
	stack<int> ts;


	int number = 1;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;

		while(a--){
			ts.push(s.top());
			s.pop();
		}
		s.push(number);
		number++;
			
		while(!ts.empty()){
			s.push(ts.top());
			ts.pop();
			}
		}
		

		
	
	
	string res = "";
	while(!s.empty()){
		int n = s.top();
		s.pop();
		res = to_string(n) + " " + res;
	}
	cout << res;
	
	return 0;
}