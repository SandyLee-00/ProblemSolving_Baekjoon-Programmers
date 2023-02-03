#include <string>
#include <vector>

using namespace std;
/*
answer에 제거하는 0의 개수 ++
길이 구하기
그 값 이진변환해서 함수에서 주기
1이면 멈추기
*/
int trCnt = 0;
int zeroCnt = 0;

string getS(string s){
    int len = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0')
            zeroCnt++;
        else
            len++;
    }
    string ret;
    while(len){
        int num = len % 2;
        ret = char(num + '0') + ret;
        len /= 2;
    }
    return ret;
}


vector<int> solution(string s) {
    vector<int> answer(2, 0);
    int cnt = 0;
    while(1){
        if(s == "1")
            break;
        s = getS(s);
        trCnt++;
    }
    answer[0] = trCnt;
    answer[1] = zeroCnt;
    
    return answer;
}