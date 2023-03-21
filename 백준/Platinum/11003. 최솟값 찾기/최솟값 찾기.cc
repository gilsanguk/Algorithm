#include <iostream>
#include <deque>

#define MAX 5000001
using namespace std;
int N, L;
struct Num {
    int idx, val;
};
deque<Num> dq;

int main() {
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++) {
        int cur;
        scanf("%d", &cur);
        if (!dq.empty() && dq.front().idx < i - L + 1) dq.pop_front();
        while (!dq.empty() && dq.back().val > cur) dq.pop_back();
        dq.push_back({i, cur});
        printf("%d ", dq.front().val);
    }

}