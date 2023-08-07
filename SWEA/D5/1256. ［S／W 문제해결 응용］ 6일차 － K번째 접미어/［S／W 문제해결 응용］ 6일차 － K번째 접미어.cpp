#include <iostream>
#include <algorithm>

using namespace std;

int K;
string subStr[401];
char tmp[401];

void input() {
    scanf("%d", &K);
    scanf("%s", tmp);
}

string solve() {
    string str(tmp);
    if (str.length() < K) return "none";
    for (int i = 0; i < str.length(); i++) {
        subStr[i] = str.substr(i);
    }
    sort(subStr, subStr + str.length());
    return subStr[K - 1];
}

int T;
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        input();
        printf("#%d ", i);
        printf("%s\n", solve().c_str());
    }
}