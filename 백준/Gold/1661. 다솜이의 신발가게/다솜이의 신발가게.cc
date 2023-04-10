#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
double P;
vector<int> shoes[3];
int price, sale;

double getSum(int i, int j, int k) {
    double ret = P;
    int tmp = 0;
    for (int l = 0; l < i; l++) {
        ret *= 0.99;
        tmp += shoes[0][l];
    }
    for (int l = 0; l < j; l++) {
        ret *= 0.98;
        tmp += shoes[1][l];
    }
    for (int l = 0; l < k; l++) {
        ret *= 0.97;
        tmp += shoes[2][l];
    }
    return ret + tmp;
}

int main() {
    scanf("%d %lf", &N, &P);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &price, &sale);
        shoes[sale-1].push_back(price);
    }
    for (auto & s : shoes) {
        sort(s.begin(), s.end());
    }
    double ans = 987654321;
    for (int i = 0; i <= shoes[0].size(); i++) {
        for (int j = 0; j <= shoes[1].size(); j++) {
            for (int k = 0; k <= shoes[2].size(); k++) {
                ans = min(ans, getSum(i, j, k));
            }
        }
    }
    printf("%.6lf", ans);
}