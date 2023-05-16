#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
struct Lecture {
    int t, val;
    bool operator<(const Lecture& rhs) const {
        if (t == rhs.t) return val < rhs.val;
        return t < rhs.t;
    }
};
vector<Lecture> lectures;
int tmp, ans;
int main() {
    scanf("%d", &N);
    int n, s, e;
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &n, &s, &e);
        lectures.push_back({s, 1});
        lectures.push_back({e, -1});
    }
    sort(lectures.begin(), lectures.end());
    for (Lecture& lecture: lectures) {
        tmp += lecture.val;
        ans = max(tmp, ans);
    }
    printf("%d", ans);
}