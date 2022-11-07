#include <iostream>
#include <cmath>

using namespace std;

struct point{
    int y;
    int x;
};
int T, N;
point p[21];
double ans;
double leng(int visited){
    pair<double, double> start = {0, 0};
    pair<double, double> end = {0, 0};
    for(int i = 0; i < N; i++){
        if (visited & (1 << i)){
            start.first += p[i].y;
            start.second += p[i].x;
        }
        else{
            end.first += p[i].y;
            end.second += p[i].x;
        }
    }
    return sqrt(pow(start.first - end.first, 2) + pow(start.second - end.second, 2));
}

void dfs(int depth, int visited, int l){
    if(depth == N/2){
        ans = min(ans, leng(visited));
        return;
    }
    for(int i = l; i < N; i++){
        dfs(depth + 1, visited | (1 << i), i + 1);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &T);
    for (int t; t < T; t++){
        scanf("%d", &N);
        ans = 1987654321;
        for (int i = 0; i < N; i++){
            scanf("%d %d", &p[i].x, &p[i].y);
        }
        dfs(0, 0, 0);
        printf("%.6f\n", ans);
    }
}