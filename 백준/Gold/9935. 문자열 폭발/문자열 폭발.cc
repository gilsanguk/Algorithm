#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Elem {
    char letter;
    int lps;
};
vector<Elem> stack;
char str[1000001];
char boom[37];
string ans;
int pos;
int main() {
    scanf("%s", str);
    scanf("%s", boom);
    int N = strlen(str);
    int M = strlen(boom);
    for (int i = 0; i < N; i++) {
        if (str[i] == boom[pos]) pos++;
        else pos = str[i] == boom[0] ? 1 : 0;
        stack.push_back({str[i], pos});
        if (pos == M) {
            stack.erase(stack.end() - pos, stack.end());
            pos = stack.back().lps;
        }
    }
    if (stack.empty()) printf("FRULA");
    for (auto & i : stack) {
        printf("%c", i.letter);
    }
}