#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[2001];
bool check(int s, int e, int diff, int idx1, int idx2){
    if (s > e) return false;
    int mid = (s + e) >> 1;
    if (arr[mid] < diff) return check(mid + 1, e, diff, idx1, idx2);
    else if (arr[mid] > diff) return check(s, mid - 1, diff, idx1, idx2);
    else {
        if (mid != idx1 && mid != idx2) return true;
        else {
            return (check(mid + 1, e, diff, idx1, idx2) || check(s, mid - 1, diff, idx1, idx2));
        }
    }
}

int solve(){
    int cnt = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i == j) continue;
            int diff = arr[i] - arr[j];
            if (check(0, N, diff, i, j)) {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+N);
    printf("%d", solve());
}