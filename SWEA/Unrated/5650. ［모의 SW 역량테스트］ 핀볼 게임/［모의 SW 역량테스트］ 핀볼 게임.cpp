#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T, N;
int map[101][101];
vector<pair<int, int>> wormhole[5];
int delta[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int rdir[6][4] = {
        {0, 0, 0, 0},
        {-1, -1, 1, 0},
        {1, -1, -1, 2},
        {3, 2, -1, -1},
        {-1, 0, 3, -1},
        {-1, -1, -1, -1}
};

int simulation(int sy, int sx, int y, int x, int d){
    int cnt = 0;
    while (true){
        y += delta[d][0], x += delta[d][1];
        if (y < 0 || y >= N || x < 0 || x >= N) return cnt * 2 + 1;
        int now = map[y][x];
        if (now == 0 && cnt == 0) return 0;
        if (y == sy && x == sx) return cnt;
        if (now == -1) return cnt;
        if (0 < now && now <= 5){
            d = rdir[now][d];
            if (d == -1) return cnt * 2 + 1;
            cnt++;
        }
        if (5 < now){
            now -= 6;
            int ny = wormhole[now][0].first, nx = wormhole[now][0].second;
            if (ny == y && nx == x){
                ny = wormhole[now][1].first, nx = wormhole[now][1].second;
            }
            y = ny, x = nx;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++){
        cin >> N;
        int res = 0;
        for (int i = 0; i < 5; i++) wormhole[i].clear();
        for (int y = 0; y < N; y++){
            for (int x = 0; x < N; x++){
                cin >> map[y][x];
                if (map[y][x] > 5) wormhole[map[y][x] - 6].push_back({y, x});
            }
        }

        for (int y = 0; y < N; y++){
            for (int x = 0; x < N; x++){
                if (map[y][x]) continue;
                for (int d = 0; d < 4; d++){
                    res = max(res, simulation(y, x, y, x, d));
                }
            }
        }
        cout << "#" << t+1 << " " << res << endl;
    }
}