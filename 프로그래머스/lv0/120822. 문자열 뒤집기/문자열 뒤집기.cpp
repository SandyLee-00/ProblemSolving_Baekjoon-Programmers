#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for(int i = 0; i < my_string.length(); i++){
        //answer += to_string(my_string.length() - i);
        answer += my_string[my_string.length() - i - 1];
    }
    return answer;
}