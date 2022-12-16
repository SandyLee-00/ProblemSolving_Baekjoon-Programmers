#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int order) {
    int answer = 0;
    string sOrder = to_string(order);
    for(int i = 0; i < sOrder.size(); i++){
        if((sOrder[i] - '0') % 3 == 0 && sOrder[i] - '0' > 0){
            answer ++;
        }
    }
    return answer;
}