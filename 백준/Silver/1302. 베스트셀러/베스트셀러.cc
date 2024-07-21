#include <iostream>
#include <map>

using namespace std;

int N;
char book[51];
map<string, int> bookCnts;

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", book);
        bookCnts[string(book)]++;
    }
}

pair<string, int> ans;
void solve() {
    for (auto it = bookCnts.begin(); it != bookCnts.end(); it++) {
        if (ans.second < it->second)
            ans = {it->first, it->second};
    }
    printf("%s", ans.first.c_str());
}

int main() {
    input();
    solve();
}