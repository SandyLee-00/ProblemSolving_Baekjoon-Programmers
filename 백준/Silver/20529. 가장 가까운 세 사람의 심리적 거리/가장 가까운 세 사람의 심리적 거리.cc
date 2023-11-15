// 가장 가까운 세 사람의 심리적 거리
/*
2명씩 가장 가까운 값만 얻었었다 
-> 문제가 1-2 2-3 3-1 사이의 최소값의 합이었다
getDis에 문자열 3개 넘겨주고 res 값 넣어놓기

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <climits>
using namespace std;

int getDis(string fir, string sec, string trd){
	int res = 0;
	for(int i = 0; i < 4; i++){
		if(fir[i] != sec[i]){
			res++;
		}
	}
	for(int i = 0; i < 4; i++){
		if(sec[i] != trd[i]){
			res++;
		}
	}
	for(int i = 0; i < 4; i++){
		if(fir[i] != trd[i]){
			res++;
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	
	while(T--){
		int N;
		cin >> N;
		
		vector<string> mbtis;
		while(N--){
			string tmp;
			cin >> tmp;
			mbtis.push_back(tmp);
		}

		int res = 0;

		if(mbtis.size() > 32){
			cout << 0 << "\n";
			continue;
		}
		else if(mbtis.size() <= 32)
		{
			priority_queue<int, vector<int>, greater<int>> respq;
			for(int i = 0; i < mbtis.size(); i++){
				for(int j = i + 1; j < mbtis.size(); j++){
					for(int k = j + 1; k < mbtis.size(); k++){
						respq.push(getDis(mbtis[i], mbtis[j], mbtis[k]));
					}
				}
			}
			res += respq.top();
				
			cout << res << "\n";
		}
	}
	
	
	return 0;
}