#include <iostream>
#include <cstring>

using namespace std;

int N, M;
char s[100001], t[100001];

string solve() {
    N = strlen(s), M = strlen(t);
    int j = 0;
    for (int i = 0; i < M; i++) {
        j += t[i] == s[j];
        if (j == N) return "Yes";
    }
    return "No";
}

int main() {
    while (~scanf("%s %s", s, t)) {
        printf("%s\n", solve().c_str());
    }
}