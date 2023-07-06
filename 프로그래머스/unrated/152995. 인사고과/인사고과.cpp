#include <vector>
#include <algorithm>

using namespace std;

// memo[i] 는 a 가 i - 1일 때, 넘겨야하는 b의 최소값
int memo[100001];
struct Score {
    int a, b, sum;
    bool operator<(const Score& rhs) const {
        return sum > rhs.sum;
    }
};
vector<Score> v;

int solution(vector<vector<int>> scores) {
    Score wanho = {scores[0][0], scores[0][1], scores[0][0] + scores[0][1]};
    int maxA = 0;
    for (auto& score : scores) {
        memo[score[0]] = max(memo[score[0]], score[1]);
        maxA = max(maxA, score[0]);
        v.push_back({score[0], score[1], score[0] + score[1]});
    }
    for (int i = maxA; i > 1; i--) {
        memo[i - 1] = max(memo[i - 1], memo[i]);
    }
    // sort(v.begin(), v.end());
    int rank = 1, tmp = 0;
    for (int i = 0; i < v.size(); i++) {
        if (wanho.a < v[i].a && wanho.b < v[i].b) return -1;
        if (memo[v[i].a + 1] > v[i].b) continue;
        if (v[i].sum > wanho.sum) rank++;
    }
    return rank;
}