#include <string>
#include <vector>

using namespace std;
/*
R
T
C
F
J
M
A
N
*/

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<int> score(30, 0);
    for(int i = 0; i < survey.size(); i++){
        int fir = survey[i][0] - 'A';
        int sec = survey[i][1] - 'A';
        int V = choices[i] - 4;
        if(V < 0)
            score[fir] += abs(V);
        if(V > 0)
            score[sec] += abs(V);
    }
    int R = score['R'-'A'];
    int T = score['T'-'A'];
    int C = score['C'-'A'];
    int F = score['F'-'A'];
    
    int J = score['J'-'A'];
    int M = score['M'-'A'];
    int A = score['A'-'A'];
    int N = score['N'-'A'];
    
    if(T > R)
        answer += 'T';
    else
        answer += 'R';
    
    if(F > C)
        answer += 'F';
    else
        answer += 'C';
    
    if(M > J)
        answer += 'M';
    else
        answer += 'J';
    
    if(N > A)
        answer += 'N';
    else
        answer += 'A';
    
    return answer;
}