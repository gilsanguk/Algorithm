#include <iostream>

using namespace std;

int N, M;
int p[500001];

int find(int x){
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) p[i] = i;
    int s, e, a, b;
    for (int i = 1; i <= M; i++){
        cin >> s >> e;
        a = find(s), b = find(e);
        if (a == b){
            cout << i;
            return 0;
        }
        p[a] = b;
    }
    cout << 0;
}