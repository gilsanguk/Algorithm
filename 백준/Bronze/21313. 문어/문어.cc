#include <iostream>

using namespace std;

int N;

void input() {
    scanf("%d", &N);
}

void solve() {
    string elem = "1 2";
    string ans;

    for(int i = 0; i < N >> 1; i++) {
        if (i != 0) ans += " ";
        ans += elem;
    }

    if (N & 1) {
        ans += " 3";
    }

    printf("%s", ans.c_str());
}

int main() {
    input();
    solve();
}