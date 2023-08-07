#include <iostream>
#include <algorithm>

using namespace std;

int N;
string arr[1001];

void solve() {
    scanf("%d", &N);
    char str[10];
    bool flag = true;
    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        arr[i] = str;
        if (arr[i] != "0") flag = false;
    }
    if (flag) {
        printf("0");
        return;
    }
    sort(arr, arr + N, [](const string& a, const string& b) {
        if (a + b > b + a) return true;
        else return false;
    });
    for (int i = 0; i < N; i++) {
        printf("%s", arr[i].c_str());
    }
}

int T;
int main() {
    solve();
}