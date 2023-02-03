#include <string>
#include <vector>
#include <bits/stdc++.h>
using ll = long long;

using namespace std;
ll fib[2050];
ll makeFib(int n){
    ll& ret = fib[n];
    if(ret != 0) return ret;
    if(n == 1) return 1;
    if(n == 2) return 2;
    ret = (makeFib(n-1) + makeFib(n-2))% 1234567;
    return ret;
}

long long solution(int n) {
    long long answer = 1;
    answer = makeFib(n);
    
    
    return answer;
}