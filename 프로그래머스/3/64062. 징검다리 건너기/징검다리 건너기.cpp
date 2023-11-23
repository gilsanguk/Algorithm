#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct stone {
    int val, idx;

    bool operator<(const stone& rhs) const {
        return val < rhs.val;
    }
};
priority_queue<stone> pq;

int solution(vector<int> stones, int k) {
    int answer = 1987654321;
    
    for (int i = 0; i < stones.size(); i++) {
        pq.push({stones[i], i});
        
        while (pq.top().idx <= i - k)
                pq.pop();
        
        if (pq.size() >= k) {
            answer = min(answer, pq.top().val);
        }
    }
    answer = min(answer, pq.top().val);
    
    return answer;
}