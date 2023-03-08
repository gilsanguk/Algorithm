#include <iostream>
#include <queue>
#define ll long long
using namespace std;

int N, a;
ll ans;
struct Node {
    int idx;
    int val;
};
queue<Node> plusQ;
queue<Node> minusQ;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a);
        if (a > 0) {
            plusQ.push({i, a});
        } else if (a < 0) {
            minusQ.push({i, a});
        }
    }
    if (plusQ.empty() || minusQ.empty()) {
        printf("0");
        return 0;
    }
    Node plusNode = plusQ.front();
    Node minusNode = minusQ.front();
    plusQ.pop();
    minusQ.pop();
    ll cur = plusNode.val + minusNode.val;
    int val;
    if (plusNode.val > -minusNode.val) {
        plusNode.val += minusNode.val;
        val = -minusNode.val;
    } else {
        minusNode.val += plusNode.val;
        val = plusNode.val;
    }
    ans += abs(plusNode.idx - minusNode.idx) * val;
    while (!plusQ.empty() || !minusQ.empty()) {
        if (cur > 0) {
            minusNode = minusQ.front();
            minusQ.pop();
            cur += minusNode.val;
            ans += abs(plusNode.idx - minusNode.idx) * min(plusNode.val, -minusNode.val);
            if (plusNode.val > -minusNode.val) {
                plusNode.val += minusNode.val;
            } else {
                minusNode.val += plusNode.val;
            }
        } else if (cur < 0) {
            plusNode = plusQ.front();
            plusQ.pop();
            cur += plusNode.val;
            ans += abs(plusNode.idx - minusNode.idx) * min(plusNode.val, -minusNode.val);
            if (plusNode.val > -minusNode.val) {
                plusNode.val += minusNode.val;
            } else {
                minusNode.val += plusNode.val;
            }
        } else {
            if (!plusQ.empty()){
                plusNode = plusQ.front();
                plusQ.pop();
            }
            if (!minusQ.empty()){
                minusNode = minusQ.front();
                minusQ.pop();
            }
            cur = plusNode.val + minusNode.val;
            ans += abs(plusNode.idx - minusNode.idx) * min(plusNode.val, -minusNode.val);
            if (plusNode.val > -minusNode.val) {
                plusNode.val += minusNode.val;
            } else {
                minusNode.val += plusNode.val;
            }
        }
    }
    printf("%lld", ans);
}