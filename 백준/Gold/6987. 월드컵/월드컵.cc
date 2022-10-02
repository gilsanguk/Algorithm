#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int scores[6][3], res;
vector<pair<int, int>> games;

int solve(int curr){
    if (curr == 15){
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 3; j++)
                if (scores[i][j]) return false;
        return true;
    }
    auto [home, away] = games[curr];
    if (scores[home][1] && scores[away][1]){
        scores[home][1]--;scores[away][1]--;
        if (solve(curr+1)) return true;
        scores[home][1]++;scores[away][1]++;
    }
    if (scores[home][0] && scores[away][2]){
        scores[home][0]--;scores[away][2]--;
        if (solve(curr+1)) return true;
        scores[home][0]++;scores[away][2]++;
    }
    if (scores[home][2] && scores[away][0]){
        scores[home][2]--;scores[away][0]--;
        if (solve(curr+1)) return true;
        scores[home][2]++;scores[away][0]++;
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