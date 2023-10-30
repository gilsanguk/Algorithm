#include <iostream>
#define ll long long
#define MOD(x) ((x) % 1000000007)

using namespace std;

int N;
ll memo[51];

ll fibo(int n) {
    if (n < 2) return 1;
    if (memo[n]) return memo[n];
    return memo[n] = MOD(fibo(n - 2) + fibo(n - 1) + 1);
}

int main() {
    scanf("%d", &N);
    printf("%d", fibo(N));
}