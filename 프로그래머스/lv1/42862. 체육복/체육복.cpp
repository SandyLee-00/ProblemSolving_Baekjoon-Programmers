#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
/*
전체 - lost 숫자
자신 것 가진 경우 
lost에서 뺴기, 빌려줌 0 체크
*/

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n - lost.size();
    vector<bool> r(40, 0);
    vector<int> lostN;
    
    for(int i = 0; i < reserve.size(); i++){
        r[reserve[i]] = 1;
    }
    for(int i = 0; i < lost.size(); i++){
        int pos = lost[i];
        if(r[pos] == 1){
            r[pos] = 0;
            answer++;
        }
        else{
            lostN.push_back(pos);
        }
    }
    sort(lostN.begin(), lostN.end());
    sort(reserve.begin(), reserve.end());
    
    for(int i = 0; i < lostN.size(); i++){
        int pos = lostN[i];
        
        if(r[pos-1] == 1){
            r[pos-1] = 0;
            answer++;
            continue;
        }
        else if(r[pos+1] == 1){
            r[pos+1] = 0;
            answer++;
        }
    }
    return answer;
}