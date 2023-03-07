#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#define MAX 1000001

using namespace std;

int N, M, Q;
char a[7], b[7];
vector<int> V[MAX];
unordered_map<string, int> name2id;
bool visited[MAX];

bool dfs(int aNum, int bNum) {
    if (aNum == bNum) return true;
    visited[aNum] = true;
    for (int i = 0; i < V[aNum].size(); i++) {
        if (visited[V[aNum][i]]) continue;
        if (dfs(V[aNum][i], bNum)) return true;
    }
    return false;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%s %s", a, b);
        string str1(a), str2(b);
        if (name2id.find(str1) == name2id.end()) {
            name2id[str1] = (int)name2id.size();
        }
        if (name2id.find(str2) == name2id.end()) {
            name2id[str2] = (int)name2id.size();
        }
        V[name2id[str1]].push_back(name2id[str2]);
    }
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%s %s", a, b);
        string str1(a), str2(b);
        if (name2id.find(str1) == name2id.end() || name2id.find(str2) == name2id.end() || str1 == str2) {
            printf("gg ");
            continue;
        }
        int aNum = name2id[str1], bNum = name2id[str2];
        memset(visited, false, sizeof(visited));
        bool A = dfs(aNum, bNum);
        memset(visited, false, sizeof(visited));
        bool B = dfs(bNum, aNum);
        if (A) {
            printf("%s ", str1.c_str());
        }
        else if (B) {
            printf("%s ", str2.c_str());
        }
        else printf("gg ");
    }
}