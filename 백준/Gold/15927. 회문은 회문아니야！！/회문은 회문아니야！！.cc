#include <iostream>
#include <cstring>

using namespace std;

int N;
char str[500001];

void input() {
    scanf("%s", str);
    N = strlen(str);
}

bool isSame() {
    for (int i = 1; i < N; i++)
        if (str[0] != str[i]) return false;
    return true;
}

bool isPalindrome() {
    for (int i = 0; i < N / 2; i++)
        if (str[i] != str[N - i - 1]) return false;
    return true;
}

int go() {
    if (isSame()) return -1;
    if (isPalindrome()) return N - 1;
    return N;
}

void solve() {
    printf("%d", go());
}

int main() {
    input();
    solve();
}