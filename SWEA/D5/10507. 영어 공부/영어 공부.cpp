#include <iostream>
#include <algorithm>

using namespace std;

int N, P;
int arr[200001];

void input() {
    scanf("%d %d", &N, &P);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
}

int solve() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int l = i, r = N - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int blank = (arr[mid] - arr[i] + 1) - (mid - i + 1);
            if (blank <= P) {
                ans = max(ans, arr[mid] + (P - blank) - arr[i] + 1);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
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