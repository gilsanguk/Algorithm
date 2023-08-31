#include <iostream>
#include <vector>

using namespace std;

int L;
char str[1000001];

void input() {
    scanf("%d", &L);
    scanf("%s", str);
}

vector<int> getFail() {
    vector<int> f(L);
    int j = 0;
    for (int i = 1; i < L; i++) {
        while (j > 0 && str[i] != str[j])
            j = f[j - 1];
        if (str[i] == str[j]) f[i] = ++j;
    }
    return f;
}

void solve() {
    vector<int> f = getFail();
    printf("%d", L - f[L - 1]);
}

int main() {
    input();
    solve();
}