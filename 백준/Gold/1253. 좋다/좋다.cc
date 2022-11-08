#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[2001];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+N);
    int ans = 0;
    for (int i = 0; i < N; i++){
        int l = 0, r = N-1;
        while(l<r){
            int sum = arr[l] + arr[r];
            if (sum == arr[i]){
                if (l != i && r != i){
                    ans++;
                    break;
                }
                if(l == i) l++;
                if(r == i) r--;
            }
            else if(sum < arr[i]) l++;
            else r--;
        }
    }
    printf("%d", ans);
}