#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;
vector<string> v;
string maxS = "0";

void input() {
    scanf("%d %d", &K, &N);
    char str[51];
    for (int i = 0; i < K; i++) {
        scanf("%s", str);
        v.push_back(str);
        if (stoi(maxS) < stoi(v[i])) maxS = v[i];
    }
}

void solve() {
    for (int i = 0; i < N - K; i++) {
        v.push_back(maxS);
    }
    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });
    for (int i = 0; i < N; i++) {
        printf("%s", v[i].c_str());
    }
}

int main() {
    input();
    solve();
}