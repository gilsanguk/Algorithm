#include <iostream>
#include <unordered_set>

using namespace std;

int N, K, ans;
int arr[101];
unordered_set<int> multiTab;

pair<int, int> getRemovePlugNum(int plug, int i) {
    for (int j = i + 1; j < K; j++) {
        if (plug == arr[j]) {
            return {j, plug};
        }
    }
    return {101, plug};
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < K; i++) {
        if (multiTab.find(arr[i]) != multiTab.end()) continue;
        if (multiTab.size() < N) multiTab.insert(arr[i]);
        else {
            ans++;
            pair<int, int> p = {0, 0};
            for (int plug : multiTab) {
                p = max(p, getRemovePlugNum(plug, i));
            }
            multiTab.erase(p. second);
            multiTab.insert(arr[i]);
        }
    }
    printf("%d", ans);
}