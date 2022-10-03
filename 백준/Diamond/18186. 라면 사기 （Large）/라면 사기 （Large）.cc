#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1000003];
long long N, B, C;
long long answer = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> B >> C;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    if(B < C){
        for(int i = 0; i < N; i++)
            answer+= arr[i];
        cout << answer*B << '\n';
        return 0;
    }

    for(int i = 0; i < N; i++){
        if(arr[i+1] > arr[i+2]){
            long long count = min(arr[i], arr[i+1] - arr[i+2]);
            answer += (B+C)*count;

            arr[i] -= count;
            arr[i+1] -= count;

            long long count2 = min(arr[i], min(arr[i+1], arr[i+2]));
            answer += (B+2*C)*count2;

            arr[i] -= count2;
            arr[i+1] -= count2;
            arr[i+2] -= count2;
        }
        else{
            long long count = min(arr[i], min(arr[i+1], arr[i+2]));
            answer += (B+2*C)*count;

            arr[i] -= count;
            arr[i+1] -= count;
            arr[i+2] -= count;

            long long count2 = min(arr[i], arr[i+1]);
            answer += (B+C)*count2;

            arr[i] -= count2;
            arr[i+1] -= count2;
        }
        answer += B*arr[i];
        arr[i] = 0;
    }

    cout << answer << '\n';
}