#include <iostream>

using namespace std;

int N, M;
int arr[101][101];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            int tmp;
            scanf("%d", &tmp);
            printf("%d ", arr[i][j]+tmp);
        }
        printf("\n");
    }
}