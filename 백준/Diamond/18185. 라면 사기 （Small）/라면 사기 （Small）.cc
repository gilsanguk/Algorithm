#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[10003];


int tri(int i){
    int cnt = min(arr[i], min(arr[i+1], arr[i+2]));
    for (int j = 0; j < 3; ++j) {
        arr[i + j] -= cnt;
    }
    return cnt * 7;
}

int bi(int i, int cnt){
    for (int j = 0; j < 2; ++j) {
        arr[i + j] -= cnt;
    }
    return cnt * 5;
}

int solve(){
    int total = 0;
    for (int i = 0; i <= N; ++i){
        if (arr[i+1] > arr[i+2]){
            int cnt = min(arr[i], arr[i+1] - arr[i+2]);
            total += bi(i,cnt);
            total += tri(i);
        }
        else{
            total += tri(i);
            int cnt = min(arr[i], arr[i+1]);
            total += bi(i,cnt);
        }
        total += arr[i] * 3;
        arr[i] = 0;
    }
    return total;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    cout << solve() << '\n';
}