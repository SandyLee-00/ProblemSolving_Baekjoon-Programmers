#include <string>
#include <vector>

using namespace std;

int solution(vector<int> box, int n) {
    int answer = 0;
    int x = box[0] / n;
    int y = box[1] / n;
    int z = box[2] / n;
    answer = x * y * z;
    
    return answer;
}