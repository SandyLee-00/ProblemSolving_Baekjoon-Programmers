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

	for(int i = 0; i < N; i++){
		int input;
		cin >> input;

		while(!s.empty()){
			int topV = s.top();
			
			if(topV <= input){
				s.pop();
			}
			else{
				break;
			}
		}
		s.push(input);
	}
	int res = 0;
	while(!s.empty()){
		res++;
		// cout << s.top() << " ";
		s.pop();
	}

	cout << res;
	
	return 0;
}