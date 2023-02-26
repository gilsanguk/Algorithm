#include <iostream>

using namespace std;

int N, M;

int main() {
    scanf("%d %d", &N, &M);
    int arr[N];
    for (int l = 0; l < N; l++) {
        arr[l] = l + 1;
    }
    while (M--) {
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);
        int size = j - i + 1;
        int tmp[size];
        for (int l = 0; l < size; l++) {
            int num = k + l;
            if (num > j) num = i + (num - j - 1);
            tmp[l] = arr[num - 1];
        }
        for (int l = i; l <= j; l++) {
            arr[l-1] = tmp[l-i];
        }
    }
    for (int l = 0; l < N; l++) {
        printf("%d ", arr[l]);
    }
}