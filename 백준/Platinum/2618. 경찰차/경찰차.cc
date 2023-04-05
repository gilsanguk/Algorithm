#include <iostream>
#include <cstring>

using namespace std;

int N, W;
struct Event {
    int y, x;
} arr[1002];
int dp[1002][1002];

int dist(int a, int b) { return abs(arr[a].y - arr[b].y) + abs(arr[a].x - arr[b].x); }

int recursive(int A, int B) {
    if (A == W || B == W) return 0;
    int &ret = dp[A][B];
    if (ret != -1) return ret;
    int next = max(A, B) + 1;
    ret = min(recursive(next, B) + dist(A, next), recursive(A, next) + dist(B, next));
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    scanf("%d", &W);
    arr[0] = {1, 1};
    arr[1] = {N, N};
    W++;
    for (int i = 2; i <= W; i++) {
        scanf("%d %d", &arr[i].y, &arr[i].x);
    }
    printf("%d\n", recursive(0, 1));
    int A = 0, B = 1;
    for (int i = 2; i <= W; i++) {
        int next = max(A, B) + 1;
        if (dp[next][B] + dist(A, next) > dp[A][next] + dist(next, B)) {
            printf("2\n");
            B = next;
        }
        else {
            printf("1\n");
            A = next;
        }
    }
}