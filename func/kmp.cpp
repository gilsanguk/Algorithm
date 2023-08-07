#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
char txt[500001];
char pat[100001];

void input() {
    scanf("%d %d", &N, &M);
    scanf("%s", txt);
    scanf("%s", pat);
    N = strlen(txt);
    M = strlen(pat);
}

vector<int> failure() {
    vector<int> f(M, 0);
    int j = 0;
    for (int i = 1; i < M; i++) {
        while (j > 0 && pat[i] != pat[j]) j = f[j - 1];
        if (pat[i] == pat[j]) f[i] = ++j;
    }
    return f;
}

int KMP() {
    int ret = 0;
    int j = 0;
    vector<int> f = failure();
    for (int i = 0; i < N; i++) {
        while (j > 0 && txt[i] != pat[j]){
            j = f[j - 1];
        }
        if (txt[i] == pat[j]) j++;
        if (j == M) {
            ret++;
            j = f[j - 1];
        }
    }
    return ret;
}

int T;
int main() {
    input();
    printf("%d\n", KMP());
}
