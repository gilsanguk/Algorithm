#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
int arr[4000001];
int rep[4000001];
int find_set(int x) {
	while (x != rep[x]) x = rep[x];
	return x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + M);
	for (int i = 0; i < M; i++) rep[i] = i;
	int num;
	for (int i = 0; i < K; i++) {
		cin >> num;
		int idx = lower_bound(arr, arr + M, num+1) - arr;
		int set_idx = find_set(idx);
		cout << arr[set_idx] << '\n';
		rep[set_idx] = find_set(set_idx + 1);
	}
}