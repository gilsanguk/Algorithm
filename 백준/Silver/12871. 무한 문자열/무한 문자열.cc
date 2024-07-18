#include <iostream>
#include <cstring>

using namespace std;

char S[51], T[51];
int N, M;

void input() {
    scanf("%s", S);
    scanf("%s", T);
    N = strlen(S);
    M = strlen(T);
}

bool solve() {
    int maxlen = N * M;
    int l = 0, r = 0;
    for (int i = 0; i < maxlen; i++) {
        if (S[l] != T[r]) {
            return false;
        }
        l = (l + 1) % N;
        r = (r + 1) % M;
    }
    return true;
}

int main() {
    input();
    printf("%d", solve());
}