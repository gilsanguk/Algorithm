#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int order[32001];
vector<int> adj[32001];

void solve(){
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++){
        if (order[i] == 0) pq.push(i);
    }
    while (!pq.empty()){
        int cur = pq.top();
        pq.pop();
        cout << cur << ' ';
        for (int next:adj[cur]){
            order[next]--;
            if (order[next] == 0) pq.push(next);
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> M;
    int s, e;
    for (int i = 0; i < M; i++){
        cin >> s >> e;
        adj[s].push_back(e);
        order[e]++;
    }
    solve();
}