#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int sudoku[9][9];
vector <pair<int, int>> blanks;

bool check(pair<int, int> p, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[p.first][i] == num) return false;
        if (sudoku[i][p.second] == num) return false;
    }
    int ny = (p.first / 3) * 3;
    int nx = (p.second / 3) * 3;
    for (int i = ny; i < ny + 3; i++) {
        for (int j = nx; j < nx + 3; j++) {
            if (sudoku[i][j] == num) return false;
        }
    }
    return true;
}

void solve(int idx) {
    if (idx == blanks.size()) {
        for (int y = 0; y < 9; y++) {
            for (int x = 0; x < 9; x++) {
                cout << sudoku[y][x] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    for (int i = 1; i <= 9; i++) {
        if (check(blanks[idx], i)) {
            sudoku[blanks[idx].first][blanks[idx].second] = i;
            solve(idx + 1);
            sudoku[blanks[idx].first][blanks[idx].second] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            cin >> sudoku[y][x];
            if (sudoku[y][x] == 0) blanks.push_back({y, x});
        }
    }
    solve(0);
}