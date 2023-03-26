#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

int N;
char str[100001][81];

class Trie {
    bool isEnd;
    unordered_map<char, Trie*> child;
public:
    void insert(const char* key) {
        Trie* cur = this;
        for (int i = 0; key[i]; i++) {
            if (cur->child[key[i]] == nullptr) {
                cur->child[key[i]] = new Trie();
            }
            cur = cur->child[key[i]];

            if (i == strlen(key) - 1) {
                cur->isEnd = true;
            }
        }
    }

    int find(const char* key) {
        int ans = 1;
        Trie* cur = child[key[0]];
        for (int i = 1; key[i]; i++) {
            if (cur->child.size() > 1 || cur->isEnd) {
                ans++;
            }
            cur = cur->child[key[i]];
        }
        return ans;
    }
};

int main(){
    while (scanf("%d", &N) != EOF) {
        memset(str, 0, sizeof(str));
        for (int i = 0; i < N; i++) {
            scanf("%s", str[i]);
        }
        Trie* root = new Trie();
        for (int i = 0; i < N; i++) {
            root->insert(str[i]);
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans += root->find(str[i]);
        }
        printf("%.2lf\n", (double)ans / N);
    }
}