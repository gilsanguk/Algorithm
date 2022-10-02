#include <iostream>
#include <algorithm>

using namespace std;
int N, r, c;
int res;

int solve(int n, int y, int x) {
    if (y == r && x == c) {
        cout << res << '\n';
        return 0;
    }

    if (y <= r && r < y + n && x <= c && c < x + n) {
        int new_n = n / 2;
        solve(new_n, y, x);
        solve(new_n, y, x + new_n);
        solve(new_n, y + new_n, x);
        solve(new_n, y + new_n, x + new_n);
    }
    else{
        res += n * n;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r >> c;
    solve((1 << N), 0, 0);
    return 0;
}