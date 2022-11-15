// 17615번 볼 모으기
#include<bits/stdc++.h>
using namespace std;
/*
1 입력 받으면서 각 문자 개수 세기
2 가장 마지막에 있는 문자 연속한 만큼 뺴기
3 둘 중 더 작은 값 리턴

2퍼에서 틀렸다고 한다. 오른쪽으로 쭉 모으는거 아닌가...?
왼쪽 모으는 것도 추가했다. 근데 그냥 다시 해야겠다.
RBBR 이건 모으는게 아닌가보다. 사진에서는 오른쪽으로 쭉 모았다.
규칙에 대해서 잘 안써있다.

1 왼쪽 R로 R움직이는 것 구하기
2 왼쪽 B로 R움직이는 것 구하기
3 오른쪽 R로 R움직이는 것 구하기
4 오른쪽 B로 R움직이는 것 구하기
5 최솟값 구하기

새로 짰는데 아까 중간에 들어간거랑 똑같이 해버렸다. 내용 수정해야한다.

*/

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	string str; cin >> str;
	int str_size = str.size();

	int endflag = 0;
	for(int i = 0; i < N; i++){
		//cout << str[i];
		if(str[i] != str[i+1]){
			break;
		}
		
	}
	if(endflag == 1){
		cout << "00";
		return 0;
	}

	int flag = 0;
	// 1 왼쪽 R로 R움직이는 것 구하기
	int lRcnt = 0;
	
	for(int i = 0; i < str_size; i++){
		if(str[i] == 'R' && flag == 1){
			lRcnt += 1;
		}
		if(str[i] == 'R' && flag == 0 && str[i+1] == 'B' || str[0] != 'R'){
			flag = 1;
		}
		
	}

	flag = 0;
	// 2 왼쪽 B로 R움직이는 것 구하기
	int lBcnt = 0;
	for(int i = 0; i < str_size; i++){
		if(str[i] == 'B' && flag == 1){
			lBcnt += 1;
		}
		if(str[i] == 'B' && flag == 0 && str[i+1] == 'R' || str[0] != 'B'){
			flag = 1;
		}
		
	}

	flag = 0;
	// 3 오른쪽 R로 R움직이는 것 구하기
	int rRcnt = 0;
	for(int i = str_size-1; i >= 0; i--){
		if(str[i] == 'R' && flag == 1){
			rRcnt += 1;
		}
		if(str[i] == 'R' && flag == 0 && str[i-1] == 'B' || str[str_size-1] != 'R'){
			flag = 1;
		}
		
	}

	flag = 0;
	// 4 오른쪽 B로 R움직이는 것 구하기
	int rBcnt = 0;
	for(int i = str_size-1; i >= 0; i--){
		if(str[i] == 'B' && flag == 1){
			rBcnt += 1;
		}
		if(str[i] == 'B' && flag == 0 && str[i-1] == 'R' || str[str_size-1] != 'B'){
			flag = 1;
		}
		
	}
	// cout <<lRcnt<<" "<<lBcnt<<" "<<rRcnt<<" "<<rBcnt<<" ";
	int res = min(lRcnt, lBcnt);
	int resr = min(rRcnt, rBcnt);

	cout << min(res, resr);
	
	return 0;
}