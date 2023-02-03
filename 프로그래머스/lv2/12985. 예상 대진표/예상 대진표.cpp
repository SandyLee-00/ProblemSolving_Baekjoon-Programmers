#include <iostream>

using namespace std;
/*
2로 나누면서 수 같으면 cnt answer
*/

int solution(int n, int a, int b)
{
    int answer = 0;
    // int len = 0;
    // while(n){
    //     len++;
    //     n /= 2;
    // }
    // string aStr, bStr;
    // while(a){
    //     aStr = char(a % 2 + '0') + aStr;
    //     a /= 2;
    // }
    // while(b){
    //     bStr = char(b % 2 + '0') + bStr;
    //     b /= 2;
    // }
    // while(aStr.size() <= len){
    //     aStr = '0' + aStr;
    // }
    // while(bStr.size() <= len){
    //     bStr = '0' + bStr;
    // }
    // cout << aStr << " " << bStr;
    
    while(1){
        answer++;
        
        a = (a+1) / 2;
        b = (b+1) / 2;
        
        if(a == b){
            break;
        }
    }
    

    return answer;
}