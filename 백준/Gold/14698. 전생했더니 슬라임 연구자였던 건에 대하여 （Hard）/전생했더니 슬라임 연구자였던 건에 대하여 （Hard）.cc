#include <iostream>
#include <queue>
using std::cin;
using std::cout;
using std::priority_queue;

int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    int T;cin >> T;
    for (int t = 0;t < T;t++) {
        priority_queue<long long> pq; // 항상 가장 작은 두 수를 빠르게 접근하기 좋은 자료구조
        int N; cin >> N;
        for (int i = 0;i < N;i++) {
            long long x; cin >> x;
            pq.push(-x); // stl의 priority queue는 max heap이므로 min heap으로 이용하기 위함
        }
        long long ans = 1;
        while (pq.size() > 1) {
            long long temp = 1;
            temp *= pq.top(); pq.pop(); // 음수 둘의 곱은 양수가 되므로 두 수를바로 곱해도 상관없다
            temp *= pq.top(); pq.pop();
            pq.push(-temp); // pq에는 원래 수를 그대로 넣어야 대소 관계가 깨지지 않는다.
            temp %= 1000000007; // 최소비용 계산에 사용하기 전에 1000000007로 나눈 나머지를 구한다
            ans *= temp;
            ans %= 1000000007;
        }
        cout << ans << '\n';
    }
    return 0;
}