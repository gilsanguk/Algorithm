#include <iostream>
#include <cmath>

using namespace std;

int a, b;

void solve() {
    scanf("%d %d", &a, &b);
    printf("%d", (int) ceil(b * log10(a)));
}

int main() {
    solve();
}