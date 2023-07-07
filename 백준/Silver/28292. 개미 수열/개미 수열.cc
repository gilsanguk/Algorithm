#include <iostream>

using namespace std;

int N;

int solve() {
    scanf("%d", &N);
    if (N > 5) return 3;
    if (N > 2) return 2;
    return 1;
}

int main() {
    printf("%d", solve());
}