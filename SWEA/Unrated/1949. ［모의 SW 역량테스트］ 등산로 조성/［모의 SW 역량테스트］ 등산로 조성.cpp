#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T, N, K;
int map[9][9];
int visited[9][9];
int delta[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int dfs(int y, int x, int height, bool flag) {
    int cnt = 0;
    visited[y][x] = 1;
    for (auto [dy, dx]: delta) {
        int ny = y + dy, nx = x + dx;
        if (0 > ny || ny >= N || 0 > nx || nx >= N || visited[ny][nx]) continue;
        if (map[ny][nx] < height){
            cnt = max(cnt, dfs(ny, nx, map[ny][nx], flag));
        }
        else if (!flag){
            for (int i = 1; i <= K; i++){
                if (map[ny][nx] - i < height){
                    cnt = max(cnt, dfs(ny, nx, map[ny][nx] - i, true));
                }
            }
        }
    }
    visited[y][x] = 0;
    return cnt + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++){
        cin >> N >> K;
        int maxV = 0, res = 0;
        for (int y = 0; y < N; y++){
            for (int x = 0; x < N; x++){
                cin >> map[y][x];
                if (map[y][x] > maxV) maxV = map[y][x];
            }
        }
        for (int y = 0; y < N; y++){
            for (int x = 0; x < N; x++){
                if (map[y][x] == maxV) {
                    int tmp = dfs(y, x, map[y][x], false);
                    res = res < tmp ? tmp : res;
                }
            }
        }

        cout << "#" << t+1 << " " << res << endl;
    }
}