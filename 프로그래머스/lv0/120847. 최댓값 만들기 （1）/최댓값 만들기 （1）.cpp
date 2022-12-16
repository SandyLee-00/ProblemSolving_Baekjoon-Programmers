#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater<>());
    int res = numbers[0] * numbers[1];
    
    answer = res;
    return answer;
}