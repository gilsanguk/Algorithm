#include <iostream>
#include <set>
#include <cstring>

using namespace std;

int K, N;
char words[401];
set<string> s;

string solve() {
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            s.insert(string(words + i, words + j + 1));
        }
    }
    if (s.size() < K) return "none";
    for (const auto & str : s) {
        if (--K == 0) return str;
    }
}

void input() {
    scanf("%d", &K);
    scanf("%s", words);
    N = strlen(words);
    s.clear();
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("#%d ", i);
        input();
        printf("%s\n", solve().c_str());
    }
}