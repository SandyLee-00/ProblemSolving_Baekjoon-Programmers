#include <string>
#include <vector>
#include <bits/stdc++.h>
using ll = long long;

using namespace std;

ll fib[100500];

ll make_fib(int n){
    ll &ret = fib[n];
    if(ret != 0) return ret;
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    else ret = (make_fib(n-1)% 1234567 + make_fib(n-2) % 1234567)% 1234567;
    return ret;
}


int solution(int n) {
    ll answer = 0;
    make_fib(n);
    answer = fib[n];
    
    return answer;
}