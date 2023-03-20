#include <iostream>
#include <cstring>
#define min3(a, b, c) min(a, min(b, c))

using namespace std;

int N, M;
char str1[1001], str2[1001];
int dp[1001][1001];

int lcs(int s1, int s2) {
    if (s1 == N && s2 == M) return 0;
    if (s1 == N) return M - s2;
    if (s2 == M) return N - s1;
    int &ret = dp[s1][s2];
    if (ret != -1) return ret;
    if (str1[s1] == str2[s2]) ret = lcs(s1 + 1, s2 + 1);
    else ret = min3(lcs(s1 + 1, s2), lcs(s1, s2 + 1), lcs(s1 + 1, s2 + 1)) + 1;
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%s", str1);
    scanf("%s", str2);
    N = strlen(str1), M = strlen(str2);
    printf("%d", lcs(0, 0));
}