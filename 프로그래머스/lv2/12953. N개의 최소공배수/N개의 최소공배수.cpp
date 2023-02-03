#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
/*

*/

int solution(vector<int> arr) {
    int answer = 0;
    
    int num = arr[0] * arr[1] / gcd(arr[0], arr[1]);
    for(int i = 2; i < arr.size(); i++){
        num = num * arr[i] / gcd(num, arr[i]);
        cout << num << "\n";
    }
    
    answer = num;
    
    return answer;
}