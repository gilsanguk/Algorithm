#include <iostream>

#define MOD(x) (x + 1234567891) % 1234567891

using namespace std;

int L, ans;
char a;

int main() {
    scanf("%d", &L);
    int r = 1;
    for (int i = 0; i < L; i++) {
        scanf(" %c", &a);
        ans += MOD((a - 'a' + 1) * r);
        r = MOD(r * 31);
    }
    printf("%d", ans);
}