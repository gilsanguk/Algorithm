#include <iostream>
#define MAX 10001

using namespace std;

int N, M;
int arr[MAX];

void input() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) 
        scanf("%d", &arr[i]);
}

int sumValue;
int ans;
int firstNumIdx;
void solve() {
    for (int i = 0; i < N; i++) {
        sumValue += arr[i];

        while (sumValue > M) { // M보다 크면 앞에서부터 제거
            sumValue -= arr[firstNumIdx++];
        }

        if (sumValue == M)
            ans++;
    }
    printf("%d", ans);
}

int main() {
    input();
    solve();
}