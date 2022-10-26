#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
vector<int> dp;
vector<int> idx;
vector<pair<int,int>> graph;

bool cmp(pair<int, int> a, pair<int,int> b){
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
void lis() {
    dp.push_back(graph[0].second);
    idx.push_back(0);
    for (int i = 1; i < N; i++){
        int next = graph[i].second;
        if (dp.back() < next){
            dp.push_back(next);
            idx.push_back(dp.size() - 1);
        }
        else {
            int index = lower_bound(dp.begin(), dp.end(), next) - dp.begin();
            dp[index] = next;
            idx.push_back((index));
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++){
        int s, e;
        cin >> s >> e;
        graph.push_back({s, e});
    }
    sort(graph.begin(), graph.end(), cmp);
    lis();
    cout << graph.size() - dp.size() << '\n';

    int MAX = dp.size() - 1;
    vector<int> ans;
    for (int i = N-1; i >= 0; i--){
        if (idx[i] == MAX) MAX--;
        else ans.push_back(graph[i].first);
    }
    for (int i = ans.size()-1; i >= 0; i--){
        cout << ans[i] << '\n';
    }
}