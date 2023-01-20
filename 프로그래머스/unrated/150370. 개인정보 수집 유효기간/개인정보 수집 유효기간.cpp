#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
/*
A-Z 배열에 달 * 28 넣기
today 파싱 -> 2000 01 01 : 1 날마다 ++
각 결과에서 
수집일자 + 각 타입 더하는 수
현재 비교
결과 업데이트
*/
int getDate(string day){
    int ret = 0;
    string tmp;
    for(int i = 0; i <= 3; i++){
        tmp += day[i];
    }
    int year = stoi(tmp) - 2000;
    ret += year * 12 * 28;
    
    tmp = "";
    for(int i = 5; i <= 6; i++){
        if(day[i] >= '0' && day[i] <= '9')
            tmp += day[i];
    }
    int month = stoi(tmp) - 1;
    ret += month * 28;
    
    tmp = "";
    for(int i = 8; i <= 9; i++){
        if(day[i] >= '0' && day[i] <= '9')
            tmp += day[i];
    }
    int d = stoi(tmp);
    ret += d;
    
    return ret;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> termV(30, 0);
    
    for(int i = 0; i < terms.size(); i++){
        string tmp = terms[i];
        int type = tmp[0] - 'A';
        string monthS = "";
        for(int j = 2; j < tmp.size(); j++)
            monthS += tmp[j];
        int month = stoi(monthS);
        termV[type] = month * 28;
    }
    int todayInt = getDate(today);
    cout << todayInt << " ";
    
    for(int i = 0; i < privacies.size(); i++){
        string str = privacies[i];
        int pDay = getDate(str);
        pDay += termV[str[str.size()-1] - 'A'] - 1;
        cout << pDay << " \n";
        if(todayInt > pDay)
            answer.push_back(i+1);
    }
    // cout << getDate("2000.01.02");
    
    return answer;
}