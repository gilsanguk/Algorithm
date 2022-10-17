#include <iostream>
#include <cstring>

using namespace std;

int dp[100][100000];
int N, K;
int bag[100][2];

int ns(int now, int capacity){
  if(now == N) return 0;
  int &ret = dp[now][capacity];
  if(ret != -1) return ret;
  ret = 0;
  int w = bag[now][0], v = bag[now][1];
  if(capacity >= w) ret = max(ns(now + 1, capacity), ns(now + 1, capacity - w) + v);
  else ret = ns(now + 1, capacity);
  return ret;
}

int main(){
    memset(dp, -1, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> bag[i][0] >> bag[i][1];
    cout << ns(0, K) << endl;
}