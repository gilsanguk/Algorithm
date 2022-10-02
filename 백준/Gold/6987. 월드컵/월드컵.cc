#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int scores[6][3], res;
vector<pair<int, int>> games;
vector<pair<int, int>> delta = {{1, 1}, {0, 2}, {2, 0}};

int solve(int curr){
    if (curr == 15){
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 3; j++)
                if (scores[i][j]) return false;
        return true;
    }
    auto [home, away] = games[curr];
    for (auto [a, b] : delta){
        if (scores[home][a] && scores[away][b]){
            scores[home][a]--;
            scores[away][b]--;
            if (solve(curr + 1)) return true;
            scores[home][a]++;
            scores[away][b]++;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 6; i++){
        for (int j = i + 1; j < 6; j++){
            games.push_back({i,j});
        }
    }

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 3; k++) {
                cin >> scores[j][k];
            }
        }
        cout << solve(0) << ' ';
        res = 0;
    }
}