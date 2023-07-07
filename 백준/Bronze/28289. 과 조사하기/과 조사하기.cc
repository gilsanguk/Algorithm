#include <iostream>

using namespace std;

int P;

void solve() {
    scanf("%d", &P);
    int a = 0, b = 0, c = 0, d = 0;
    int G, C, N;
    for (int i = 0; i < P; i++) {
        scanf("%d %d %d", &G, &C, &N);
        if (G == 1) {
            d++;
            continue;
        }
        else {
            if (C == 1 || C == 2) a++;
            else if (C == 3) b++;
            else c++;
        }
    }
    printf("%d\n%d\n%d\n%d", a, b, c, d);
}

int main() {
    solve();
}