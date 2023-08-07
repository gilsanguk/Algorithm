#include <iostream>
#include <unordered_set>

using namespace std;

int N, M;
unordered_set<string> A;
unordered_set<string> B;

void input() {
    scanf("%d %d", &N, &M);
    A.clear();
    B.clear();
    char str[51];
    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        A.insert(str);
    }
    for (int i = 0; i < M; i++) {
        scanf("%s", str);
        B.insert(str);
    }
}


int solve() {
    int cnt = 0;
    for (const auto & it : A) {
        if (B.find(it) != B.end()) {
            cnt++;
        }
    }
    return cnt;
}

int T;
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("#%d ", i);
        input();
        printf("%d\n", solve());
    }
}