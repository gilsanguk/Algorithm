#include <cstdio>
#define MAX 2001
#define HASH_SIZE ((1 << 30) - 1)
#define ll long long

using namespace std;

int getMaxPower(int len, int shift) {
    ll ret = 1;
    for (int i = 1; i < len; i++) {
        ret = (ret << shift) + ret;
    }
    return (int) (ret & HASH_SIZE);
}

int GetHash(const int src[], int len, int shift) {
    ll ret = 0;
    for (int i = 0; i < len; i++) {
        ret = (ret << shift) + ret + src[i];
    }
    return (int) (ret & HASH_SIZE);
}

int GetNext(int prev, int del, int power, int add, int shift) {
    ll ret = prev - del * power;
    ret = (ret << shift) + ret + add;
    return (int) (ret & HASH_SIZE);
}

int H, W, N, M;
int arr[MAX][MAX], pat[MAX][MAX];
int hashArr[MAX][MAX], horizon[MAX][MAX];

int solve() {
    for (int i = 0; i < H; i++)
        horizon[0][i] = GetHash(pat[i], W, 4);
    int patHash = GetHash(horizon[0], H, 5);

    int maxY = getMaxPower(H, 5);
    int maxX = getMaxPower(W, 4);
    for (int i = 0; i < N; i++) {
        horizon[0][i] = GetHash(arr[i], W, 4);
        for (int j = 1; j <= M - W; j++) {
            horizon[j][i] = GetNext(horizon[j - 1][i], arr[i][j - 1], maxX, arr[i][j + W - 1], 4);
        }
    }
    for (int i = 0; i <= M - W; i++) {
        hashArr[0][i] = GetHash(horizon[i], H, 5);
        for (int j = 1; j <= N - H; j++) {
            hashArr[j][i] = GetNext(hashArr[j - 1][i], horizon[i][j - 1], maxY, horizon[i][j + H - 1], 5);
        }
    }

    int cnt = 0;
    for (int i = 0; i <= N - H; i++)
        for (int j = 0; j <= M - W; j++)
            if (hashArr[i][j] == patHash) cnt++;
    return cnt;
}

char str[MAX];
void input() {
    scanf("%d %d %d %d", &H, &W, &N, &M);
    for (int y = 0; y < H; y++) {
        scanf("%s", str);
        for (int x = 0; x < W; x++) {
            pat[y][x] = str[x] == 'o';
        }
    }
    for (int y = 0; y < N; y++) {
        scanf("%s", str);
        for (int x = 0; x < M; x++) {
            arr[y][x] = str[x] == 'o';
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("#%d ", i);
        input();
        printf("%d\n", solve());
    }
}