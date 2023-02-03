#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string fir(string str){
    string ret;
    for(int i = 0; i < str.size(); i++){
        if(isupper(str[i]))
            str[i] = tolower(str[i]);
    }
    ret = str;
    return ret;
}

string sec(string str){
    string ret;
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'a' && str[i] <= 'z')
            ret += str[i];
        if(str[i] >= '0' && str[i] <= '9')
            ret += str[i];
        if(str[i] == '-' || str[i] == '_' || str[i] == '.')
            ret += str[i];
    }
    return ret;
}

string thir(string str){
    string ret;
    ret += str[0];
    for(int i = 1; i < str.size(); i++){
        if(str[i] == '.' && str[i-1] == '.')
            continue;
        ret += str[i];
    }
    return ret;
}

string four(string str){
    string ret;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '.'){
            if(i == 0 || i == str.size()-1)
                continue;
        }
        ret += str[i];
    }
    
    return ret;
}

string fif(string str){
    string ret = str;
    if(ret.empty())
        ret = "a";
    return ret;
}

string six(string str){
    string ret;
    for(int i = 0; i < 15 && i < str.size(); i++){
        ret += str[i];
    }
    ret = four(ret);
    return ret;
}

string sev(string str){
    string ret = str;
    while(1){
        if(ret.size() >= 3)
            break;
        ret += str[str.size()-1];
    }
    return ret;
}

string solution(string new_id) {
    string answer = "";
    answer = fir(new_id);
    answer = sec(answer);
    answer = thir(answer);
    answer = four(answer);
    answer = fif(answer);
    answer = six(answer);
    answer = sev(answer);
    
    return answer;
}