#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int getDist (int x1, int x2, int y1, int y2) {
    return pow(y2 - y1, 2) + pow(x2 - x1, 2);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for (auto& ball: balls) {
        int y = ball[1], x = ball[0];
        int res = 987654321;
        if (startX != x) {
            res = min(res, getDist(x, startX, n + (n - y), startY));
            res = min(res, getDist(x, startX, -y, startY));
        }
        else {
            int tmp;
            if (startY > y) tmp = pow(n - y + n - startY, 2);
            else tmp = pow(y + startY, 2);
            res = min(res, tmp);
        }
        if (startY != y) {
            res = min(res, getDist(m + (m - x), startX, y, startY));
            res = min(res, getDist(-x, startX, y, startY));
        }
        else {
            int tmp;
            if (startX > x) tmp = pow(m - x + m - startX, 2);
            else tmp = pow(x + startX, 2);
            res = min(res, tmp);
        }
        answer.push_back(res);
    }
    return answer;
}