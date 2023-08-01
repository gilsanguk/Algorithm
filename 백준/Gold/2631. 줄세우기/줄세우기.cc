#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[201], dp[201];
int solve(int s) {
    int& ret = dp[s + 1];
    if (ret != -1) return ret;
    ret = 1;
    for (int nxt = s + 1; nxt < N; nxt++)
        if (s == -1 || arr[s] < arr[nxt])
            ret = max(ret, solve(nxt) + 1);
    return ret;
}

void input() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
}

int main() {
    input();
    printf("%d", N - (solve(-1) - 1));
}