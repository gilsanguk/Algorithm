#include <iostream>

using namespace std;

int N;
int arr[10];

void input() {
    scanf("%d", &N);
}

void solve() {
    int ten = 1, prv = 0;
    while (N) {
        int x = N % 10;
        N /= 10;
        for (int i = 0; i <= 9; i++)
            arr[i] += i < x ? (N + 1) * ten : N * ten;
        arr[x] += prv + 1;
        arr[0] -= ten;
        prv += x * ten;
        ten *= 10;
    }
    for (int i : arr)
        printf("%d ", i);
}

int main() {
    input();
    solve();
}