#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<string> v;

void input() {
    scanf("%d", &N);
    v.resize(N);
    char temp[51];
    for (int i = 0; i < N; i++) {
        scanf("%s", temp);
        v[i] = temp;
    }
}

void solve() {
    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        if (a.length() == b.length()) return a < b;
        return a.length() < b.length();
    });
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto& s : v) {
        printf("%s\n", s.c_str());
    }
}

int T;
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        input();
        printf("#%d \n", i);
        solve();
    }
}