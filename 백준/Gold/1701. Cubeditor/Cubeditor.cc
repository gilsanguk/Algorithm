#include <iostream>
#include <vector>

using namespace std;

int N;
char arr[5001];
int ans = 0;

void lps(string str) {
    vector<int> Pi(str.length());
    for (int i = 1, j = 0; i < str.length(); i++) {
        while (j > 0 && str[i] != str[j]) j = Pi[j - 1];
        if (str[i] == str[j]) {
            Pi[i] = ++j;
            ans = max(ans, Pi[i]);
        }
    }
}

void solve() {
    scanf("%s", arr);
    string str(arr);
    N = str.length();
    for (int i = 0; i < N; i++) {
        lps(str.substr(i, N - i));
    }
    printf("%d", ans);
}

int main() {
    solve();
}