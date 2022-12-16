#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    
    for(int i = 0; i < num_list.size(); i += n){
        vector<int> nums(n, 0);
        for(int j = 0; j < n; j++){
            nums[j] = num_list[i + j];
        }
        answer.push_back(nums);
    }
    return answer;
}