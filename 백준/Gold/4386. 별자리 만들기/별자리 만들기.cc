#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define y first
#define x second

using namespace std;

int N;
vector<pair<double, double>> V;
double graph[101][101];
bool visited[101];

double prim(){
    double ret = 0;
    priority_queue<pair<double, int>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        double cost = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(visited[curr]) continue;
        visited[curr] = true;
        ret += cost;
        for(int next = 0; next < N; next++){
            if(!visited[next]){
                pq.push({-graph[curr][next], next});
            }
        }
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        double x, y;
        scanf("%lf %lf", &x, &y);
        V.push_back({y, x});
    }
    for (int s = 0; s < N; s++){
        for (int e = 0; e < N; e++){
            graph[s][e] = sqrt(pow(V[s].y - V[e].y, 2) + pow(V[s].x - V[e].x, 2));
        }
    }
    printf("%.2lf", prim());
}