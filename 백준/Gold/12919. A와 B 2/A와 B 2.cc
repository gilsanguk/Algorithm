#include <iostream>
#include <algorithm>

#define MAX 51

using namespace std;

int ans = 0;

void solve(const string& S, string T) {
    if (S == T){
        ans = 1;
        return;
    }
    if (S.size() > T.size()) return;
    if (T[T.size() - 1] == 'A') {
        solve(S, T.substr(0, T.size() - 1));
    }
    if (T[0] == 'B') {
        string tmp = T;
        reverse(tmp.begin(), tmp.end());
        solve(S, tmp.substr(0, T.size() - 1));
    }
}

int main() {
    char S[MAX], T[MAX];
    scanf("%s", &S);
    scanf("%s", &T);
    solve(S, T);
    printf("%d\n", ans);
}