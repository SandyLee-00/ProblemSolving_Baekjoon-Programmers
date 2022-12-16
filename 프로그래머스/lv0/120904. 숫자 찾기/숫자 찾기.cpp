#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int num, int k) {
    int answer = 0;
    string toSNum = to_string(num);
    for(int i = 0; i < toSNum.size(); i++){
        if(toSNum[i] - '0' == k){
            answer = i + 1;
            return answer;
        }
    }
    return -1;
}