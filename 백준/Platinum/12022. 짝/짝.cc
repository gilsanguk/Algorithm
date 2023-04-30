#include <iostream>
#include <unordered_map>

using namespace std;

int N;
int mal[1001][1001];
int fem[1001][1001];
unordered_map<int, int> f2m[1001];
int mMarriage[1001];
int fMarriage[1001];

void solve() {
    int remain = N, cur;
    while (remain) {
        for (cur = 1; cur <= N; cur++) {
            if (mMarriage[cur] == 0) break;
        }
        for (int i = 1; i <= N && mMarriage[cur] == 0; i++) {
            int f = mal[cur][i], prv = fMarriage[f];
            if (prv == 0) {
                mMarriage[cur] = f;
                fMarriage[f] = cur;
                remain--;
            }
            else {
                if (f2m[f][prv] > f2m[f][cur]) {
                    mMarriage[prv] = 0;
                    mMarriage[cur] = f;
                    fMarriage[f] = cur;
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        printf("%d\n", mMarriage[i]);
    }
}


void input() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &mal[i][j]);
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &fem[i][j]);
        }
    }
}

void init() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            f2m[i][fem[i][j]] = j;
        }
    }
}

int main() {
    scanf("%d", &N);
    input();
    init();
    solve();
}