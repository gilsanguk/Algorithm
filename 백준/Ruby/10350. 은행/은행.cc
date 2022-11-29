#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

int N;
ll arr[20001];
ll pSum[20002];
ll Sum = 0;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	double ans = 0;
	scanf("%d", &N);
	pSum[0] = 0;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
		Sum += arr[i];
		arr[N + i] = arr[i];
	}
	for (int i = 0; i < 2 * N; i++) {
		pSum[i + 1] = pSum[i] + arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j <= N+i; j++) {
			ll sub = pSum[j] - pSum[i];
			if (sub < 0) ans += ceil((double) -sub/Sum);
		}
	}
	printf("%.lf", ans);
}