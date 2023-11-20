// 이중 우선순위 큐
/*
pq 두 개로 풀려고 했는데 순서 섞인다
-> multiemap으로 begin, end 쓴다 

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <climits>
#include <set>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while(T--){
		multiset<int> ms;
		
		int k;
		cin >> k;
		for(int i = 0; i < k; i++){
			char command;
			cin >> command;
			int num;
			cin >> num;
			
			if(command == 'I'){
				ms.insert(num);
			}
			else if(ms.size() == 0){
				continue;
			}
			else if(command == 'D' && num == -1){
				auto iter = ms.begin();
				ms.erase(iter);
			}
			else if(command == 'D' && num == 1){
				auto iter = ms.end();
				ms.erase((--iter));
			}
		}
		if(ms.size() == 0){
			cout << "EMPTY\n"; 
		}
		else{
			cout << *(--ms.end()) << " "<< *(ms.begin()) << "\n";
		}
	}
	
	return 0;
}