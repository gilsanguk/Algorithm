#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int T, N;
int arr[14] = {0, 0, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68};
void solve(int n){
   stack<int> s;
   while (n > 13){
       if (n == 17){
           s.push(200);
           n = 0;
           break;
       }
       s.push(8);
       n -= 7;
   }
   if(n != 0) s.push(arr[n]);
   while(!s.empty()){
       printf("%d", s.top());
       s.pop();
   }
   printf(" ");
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        solve(N);
        if (N & 1){
            printf("7");
            N -= 3;
        }
        for (int i = 0; i < (N >> 1); i++){
            printf("1");
        }
        printf("\n");
    }
}