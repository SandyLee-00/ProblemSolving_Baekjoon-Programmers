#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
/*
10 -> 2 로 변환, 1 카운트 세기
계속 1 카운트 세기
*/

int ret1Cnt(int n){
    int ret = 0;
    while(1){
        if(n == 0) break;
        if(n % 2 == 1)
            ret ++;
        n /= 2;
    }
    return ret;
}

int solution(int n) {
    int answer = 0;
    int nCnt = ret1Cnt(n);
    for(int i = n + 1; i <= 1010000; i++){
        int iCnt = ret1Cnt(i);
        if(iCnt == nCnt){
            answer = i;
            break;
        }
    }
    
    return answer;
}