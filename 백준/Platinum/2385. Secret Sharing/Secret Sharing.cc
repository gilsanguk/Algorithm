#include <iostream>
#include <algorithm>

using namespace std;

int N;
string share[101];
string ans;
bool cmp(const string& S1, const string& S2) {
    return S1 + S2 < S2 + S1;
}
bool comZero (const string& S1, const string& S2) {
    return S1 + ans + S2 < S2 + ans + S1;
}

void solve() {
    sort(share, share + N, cmp);
    int i = 0;
    for (; i < N && share[i][0] == '0'; i++) {
        ans += share[i];
    }
    if (i != N) {
        int tmp = min_element(share + i, share + N, comZero) - share;
        cout << share[tmp];
        for (i = 0; i < N; i++) {
            if (i != tmp) {
                cout << share[i];
            }
        }
    }
    else {
        cout << "INVALID";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> share[i];
    }
    solve();
}