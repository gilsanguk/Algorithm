#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
struct Problem {
    int num, hard;
    bool operator<(const Problem& rhs) const {
        if (hard == rhs.hard) return num < rhs.num;
        return hard < rhs.hard;
    }
    bool operator>(const Problem& rhs) const {
        if (hard == rhs.hard) return num > rhs.num;
        return hard > rhs.hard;
    }
};
priority_queue<Problem> maxQ;
priority_queue<Problem, vector<Problem>, greater<>> minQ;

int P, L;
int problem[100001];
void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &P, &L);
        maxQ.push({P, L});
        minQ.push({P, L});
        problem[P] = L;
    }
    scanf("%d", &M);
}

char cmd[10];
int x;
void solve() {
    for (int i = 0; i < M; i++) {
        scanf("%s", cmd);
        if (strcmp(cmd, "recommend") == 0) {
            scanf("%d", &x);
            if (x == 1) {
                while (problem[maxQ.top().num] != maxQ.top().hard) maxQ.pop();
                printf("%d\n", maxQ.top().num);
            } else {
                while (problem[minQ.top().num] != minQ.top().hard) minQ.pop();
                printf("%d\n", minQ.top().num);
            }
        }
        if (strcmp(cmd, "add") == 0) {
            scanf("%d %d", &P, &L);
            maxQ.push({P, L});
            minQ.push({P, L});
            problem[P] = L;
        }
        if (strcmp(cmd, "solved") == 0) {
            scanf("%d", &P);
            problem[P] = -1;
        }
    }
}

int main() {
    input();
    solve();
}