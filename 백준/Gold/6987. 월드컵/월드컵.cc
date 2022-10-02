#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int scores[6][3];
vector<pair<int, int>> delta = {{1, 1}, {0, 2}, {2, 0}};

int solve(int home, int away){
    if (home == 5){
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 3; j++)
                if (scores[i][j]) return false;
        return true;
    }
    for (auto [a, b] : delta){
        if (scores[home][a] && scores[away][b]){
            scores[home][a]--;
            scores[away][b]--;
            if (away == 5) {if (solve(home + 1, home + 2)) return true;}
            else {if (solve(home, away + 1)) return true;}
            scores[home][a]++;
            scores[away][b]++;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 3; k++) {
                cin >> scores[j][k];
            }
        }
        cout << solve(0, 1) << ' ';
    }
}