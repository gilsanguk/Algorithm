#include <iostream>
#include <map>

using namespace std;

int N, M;
char board[1001][1001];
int visited[1001][1001];
map <char, pair<int,int>> delta = {{'U', {-1,0}}, {'D', {1,0}}, {'L', {0,-1}}, {'R', {0,1}}};

bool dfs(int y, int x){
    if(visited[y][x] == 1) return true;
    if(visited[y][x] == 2) return false;
    visited[y][x] = 1;
    bool ret = dfs(y + delta[board[y][x]].first, x + delta[board[y][x]].second);
    visited[y][x] = 2;
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> board[y][x];
        }
    }
    int cnt = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if(visited[y][x] == 0){
                if(dfs(y,x)) cnt++;
            }
        }
    }
    cout << cnt;
}