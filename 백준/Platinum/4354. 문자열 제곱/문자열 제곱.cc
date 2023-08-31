#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
char str[1000001];

void input() {
    scanf("%s", str);
    N = strlen(str);
}

vector<int> getFail() {
    vector<int> f(N);
    int j = 0;
    for (int i = 1; i < N; i++) {
        while (j > 0 && str[i] != str[j])
            j = f[j - 1];
        if (str[i] == str[j]) f[i] = ++j;
    }
    return f;
}

void solve() {
    vector<int> f = getFail();
    int ans = N - f[N - 1];
    printf("%d\n", N % ans ? 1 : N / ans);
}

int main() {
    while (true) {
        scanf("%s", str);
        if (strcmp(str, ".") == 0) break;
        N = strlen(str);
        solve();
    }
}