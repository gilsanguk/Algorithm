#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[40001];
void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
}

vector<int> memo = {-1, };
void solve() {
    for (int i = 0; i < N; i++) {
        if (memo.back() < arr[i]) memo.push_back(arr[i]);
        else {
            auto it = lower_bound(memo.begin(), memo.end(), arr[i]);
            *it = arr[i];
        }
    }
    printf("%d", memo.size() - 1);
}

int main() {
    input();
    solve();
}