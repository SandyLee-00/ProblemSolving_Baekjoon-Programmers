#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    int minX = 999, minY = 999, maxX = -999, maxY = -999;
    for(int i = 0; i < dots.size(); i++){
        minX = min(minX, dots[i][0]);
        minY = min(minY, dots[i][1]);
        maxX = max(maxX, dots[i][0]);
        maxY = max(maxY, dots[i][1]);
    }
    answer = (maxX - minX) * (maxY - minY);
    return answer;
}