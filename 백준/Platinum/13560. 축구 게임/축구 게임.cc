#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[10001];

void input() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
}

int solve() {
    sort(arr + 1, arr + N + 1, greater<>());
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (N - i < arr[i]) {
            cnt -= arr[i] - (N - i);
            if (cnt < 0) return -1;
        }
        if (N - i > arr[i]) cnt += N - i - arr[i];
    }
    if (cnt != 0) return -1;
    return 1;
}

int main() {
    input();
    printf("%d", solve());
}