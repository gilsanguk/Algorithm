#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct Lecture {
    int id;
    int start, end;

    bool operator<(const Lecture &l) const {
        if (start == l.start) return end < l.end;
        return start < l.start;
    }
} lectures[100001];
int N;
map<int, int> ans;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &lectures[i].id, &lectures[i].start, &lectures[i].end);
    }
    sort(lectures, lectures + N);
    int cnt = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    ans.insert({lectures[0].id, cnt});
    pq.push({lectures[0].end, cnt});
    for (int i = 1; i < N; i++) {
        pair<int, int> cur = pq.top();
        if (cur.first > lectures[i].start) {
            ans.insert({lectures[i].id, ++cnt});
            pq.push({lectures[i].end, cnt});
        } else {
            pq.pop();
            ans.insert({lectures[i].id, cur.second});
            pq.push({lectures[i].end, cur.second});
        }
    }
    printf("%d\n", cnt);
    for (auto &it : ans) {
        printf("%d\n", it.second);
    }
}