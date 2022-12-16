#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 1;
    int fac = 1;
    int num = 1;
    while(1){
        if(num > n)
            break;
        
        num *= fac;
        if(num <= n){
            answer = fac;
        }
        fac++;
    }
    
    return answer;
}