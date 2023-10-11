#include <iostream>

using namespace std;

int N;
int arr[5001];
bool visited[400001];

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
}

void solve() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (visited[arr[i] - arr[j] + 200000]) {
                ans++;
                break;
            }
        }
        for (int j = 0; j <= i; j++)
            visited[arr[i] + arr[j] + 200000] = true;
    }
    printf("%d", ans);
}

int main() {
    input();
    solve();
}