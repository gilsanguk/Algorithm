#include <iostream>
#include <cmath>

using namespace std;

int a, b;

void solve() {
    scanf("%d %d", &a, &b);
    long double c = log10(a);
    if (c == (int) c) c++;
    printf("%d", (int) ceil(b * c));
}

int main() {
    solve();
}