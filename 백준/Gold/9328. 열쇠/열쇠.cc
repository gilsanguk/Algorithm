#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int T, H, W;
char MAP[102][102];
bool visited[102][102];
bool key[26];
string primary_key;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int bfs(int y, int x){
    queue<pair<int, int>> q;
    vector<pair<int,int>> door[26];
    q.push({y, x});
    visited[y][x] = true;
    int cnt = 0;
    while (!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i], nx = x + dx[i];
            if (0 <= ny && ny <= H+1 && 0 <= nx && nx <= W+1){
                char& curr = MAP[ny][nx];
                if (curr == '*' || visited[ny][nx]) continue;
                visited[ny][nx] = true;
                if (curr == '$') cnt++;
                if ('A' <= curr && curr <= 'Z'){
                    if (key[curr-'A']) q.push({ny, nx});
                    else door[curr-'A'].push_back({ny,nx});
                }
                else if ('a' <= curr && curr <= 'z'){
                    q.push({ny, nx});
                    key[curr - 'a'] = true;
                    for (int j = 0; j < door[curr - 'a'].size(); j++){
                        q.push(door[curr-'a'][j]);
                    }
                }
                else q.push({ny, nx});
            }
        }
    }
    return cnt;
}

void solve(){
    memset(MAP, '.', sizeof(MAP));
    memset(visited, false, sizeof(visited));
    memset(key, false, sizeof(key));
    primary_key.clear();
    cin >> H >> W;
    for (int y = 1; y <= H; y++){
        for (int x = 1; x <= W; x++){
            cin >> MAP[y][x];
        }
    }
    cin >> primary_key;
    for (int i = 0; i < primary_key.length(); i++){
        if (primary_key[i] == '0') break;
        key[primary_key[i] - 'a'] = true;
    }
    cout << bfs(0, 0) << '\n';
}

int main(){
    cin >> T;
    for (int t=0; t < T; t++){
        solve();
    }
}