#include <iostream>
#include <cstring>

using namespace std;

int N;
char str[101];
int cnt[26];

void solve() {
    scanf("%s", str);
    N = strlen(str);
    for (int i = 0; i < N; i++)
        cnt[str[i] - 'a']++;
    for (int i = 0; i < 26; i++)
        printf("%d ", cnt[i]);
}

int main() {
    solve();
}