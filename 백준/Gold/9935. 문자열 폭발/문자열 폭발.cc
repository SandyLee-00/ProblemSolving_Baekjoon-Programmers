// 9935번 문자열 폭발
/*
문자 하나씩 넣으면서 뒤에 문자 일치하면 앞에 내용 하나씩 빼기
아이디어는 맞았는데 구현을 못했다. 

하나씩 X 조건 체크해서 빼기

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <sstream>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;

	string target;
	cin >> target;
	int tLastIdx = target.size() - 1;

	string temp;

	for(int i = 0; i < str.size(); i++){
		temp += str[i];
		// cout << temp << "\n";
		int tempLastIdx = temp.size() - 1;

		// #str[i]가 target[tLastIdx]와 일치 -> 쭉 일치하는지 체크
		if(temp.size() >= target.size() &&
			target[tLastIdx] == str[i]){
			bool flag = true;
			
			for(int j = 0; j < target.size(); j++){
				// cout << target[tLastIdx - j] << " " << temp[tempLastIdx - j];
				if(target[tLastIdx - j] != temp[tempLastIdx - j]){
					flag = false;
					break;
				}
			}

			if(flag == true){
				temp.erase(temp.end() - target.size(), temp.end());
			}
		}
	}

	if(temp.empty()){
		cout << "FRULA";
	}
	else{
		cout << temp;

	}


	return 0;
}