#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    
    vector<bool> isPrime(10000, 1);
    for(int i = 2; i * i <= 10000; i++){
        for(int j = i * 2; j <= 10000; j += i){
            isPrime[j] = 0;
        }
    }

    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
            for(int k = j + 1; k < nums.size(); k++){
                int num = nums[i] + nums[j] + nums[k];
                if(isPrime[num])
                    answer += 1;
            }
        }
    }
    

    return answer;
}