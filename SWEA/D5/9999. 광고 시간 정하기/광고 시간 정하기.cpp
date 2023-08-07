#include <iostream>
#include <algorithm>

using namespace std;

int L, N;
struct Time {
    int s, e;
} arr[100001];
int pSum[100001];

int upperBound(int target) {
    int ret = N;
    int l = 0, r = N - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid].e > target) {
            ret = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ret;
}

void input() {
    scanf("%d %d", &L, &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i].s, &arr[i].e);
        if (i == 0) pSum[i] = arr[i].e - arr[i].s;
        else pSum[i] = pSum[i - 1] + arr[i].e - arr[i].s;
    }

}

int solve() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int target = arr[i].s + L;
        int idx = upperBound(target);
        int tmp = pSum[idx - 1];
        if (i != 0) tmp -= pSum[i - 1];
        if (idx != N && target > arr[idx].s) tmp += target - arr[idx].s;
        ans = max(ans, tmp);
    }
    return ans;
}

int T;
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        input();
        printf("#%d ", i);
        printf("%d\n", solve());
    }
}