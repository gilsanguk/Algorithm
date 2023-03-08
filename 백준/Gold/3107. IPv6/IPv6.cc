#include <iostream>
#include <cstring>

using namespace std;

char address[40];
int len;

void addString(string &str, int i, int &k) {
    for (int j = 4 - k; j > 0; j--) {
        str += '0';
    }
    for (int j = 0; j < k; j++) {
        str += address[i - k + j];
    }
    k = 0;
    if (i != len) {
        str += ':';
    }
}

void solve(string &front, string &back) {
    int k = 0;
    bool flag = false;
    for (int i = 0; i < len; i++) {
        if (address[i] != ':') {
            k++;
        }
        else {
            if (i != 0 && address[i - 1] == ':') {
                flag = true;
                continue;
            }
            if (!flag) {
                addString(front, i, k);
            } else {
                addString(back, i, k);
            }
        }
    }
    if (k != 0) {
        if (!flag) {
            addString(front, len, k);
        } else {
            addString(back, len, k);
        }
    } else {
        if (flag) {
            back += "0000";
        }
    }
}

int main() {
    scanf("%s", address);
    len = (int) strlen(address);
    string front, back;
    solve(front, back);
    if (front.length() + back.length() < 39) {
        int n = 39 - (int) (front.length() + back.length());
        for (int i = 1; i <= n; i++) {
            front += i % 5 == 0 ? ':' : '0';
        }
    }
    printf("%s%s", front.c_str(), back.c_str());
}