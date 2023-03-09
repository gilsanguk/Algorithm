#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[3];
int max_dp[3];
int min_dp[3];

int main() {
    scanf("%d", &N);
    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
    memcpy(max_dp, arr, sizeof(arr));
    memcpy(min_dp, arr, sizeof(arr));
    for (int i = 1; i < N; i++) {
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
        int tmp[3];
        memcpy(tmp, max_dp, sizeof(max_dp));
        max_dp[0] = max(tmp[0], tmp[1]) + arr[0];
        max_dp[1] = max(max(tmp[0], tmp[1]), tmp[2]) + arr[1];
        max_dp[2] = max(tmp[1], tmp[2]) + arr[2];
        memcpy(tmp, min_dp, sizeof(min_dp));
        min_dp[0] = min(tmp[0], tmp[1]) + arr[0];
        min_dp[1] = min(min(tmp[0], tmp[1]), tmp[2]) + arr[1];
        min_dp[2] = min(tmp[1], tmp[2]) + arr[2];
    }
    pair<int, int> ans;
    ans.first = max(max(max_dp[0], max_dp[1]), max_dp[2]);
    ans.second = min(min(min_dp[0], min_dp[1]), min_dp[2]);
    printf("%d %d", ans.first, ans.second);
}