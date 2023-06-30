#include <iostream>
#include <unordered_map>

using namespace std;

int sy, sm, sd;
int ey, em, ed;

bool isYoon(int y) {
    if (y % 4 == 0) {
        if (y % 100 == 0) {
            if (y % 400 == 0) return true;
            return false;
        }
        return true;
    }
    return false;
}

int m2d[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int getDay(int y, int m, int d) {
    int day = 0;
    for (int i = 1; i < y; i++) {
        if (isYoon(i)) day += 366;
        else day += 365;
    }
    for (int i = 1; i < m; i++) {
        if (i == 2 && isYoon(y)) day += 29;
        else day += m2d[i];
    }
    day += d;
    return day;
}

void solve() {
    scanf("%d %d %d", &sy, &sm, &sd);
    scanf("%d %d %d", &ey, &em, &ed);
    int dDay = getDay(ey, em, ed);
    if (dDay >= getDay(sy + 1000, sm, sd)) printf("gg");
    else printf("D-%d", dDay - getDay(sy, sm, sd));
}

int main() {
    solve();
}