#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int crane[51];
vector<int> box;

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &crane[i]);
    scanf("%d", &M);
    box.resize(M);
    for (int i = 0; i < M; i++)
        scanf("%d", &box[i]);
}

int go() {
    if (box[0] > crane[0]) return -1;
    int cnt = 0;
    while (!box.empty()) {
        cnt++;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < box.size(); j++) {
                if (crane[i] >= box[j]) {
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
    }
    return cnt;
}

void solve() {
    sort(crane, crane + N, [](int a, int b) { return a > b; });
    sort(box.begin(), box.end(), [](int a, int b) { return a > b; });
    printf("%d", go());
}

int main() {
    input();
    solve();
}