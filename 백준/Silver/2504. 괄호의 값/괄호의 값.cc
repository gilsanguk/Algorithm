#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

char str[31];
unordered_map<char, int> num = {{'(', 2}, {'[', 3}};
unordered_map<char, char> same = {{')', '('}, {']', '['}};

int solve() {
    scanf("%s", str);
    vector<char> stack;
    int ans = 0, tmp = 1;
    for (int i = 0; str[i]; i++) {
        char &c = str[i];
        // 여는 괄호
        if (c == '(' || c == '[') {
            tmp *= num[c];
            stack.push_back(c);
        }
        // 닫는 괄호
        else {
            // 올바르지 못한 괄호열
            if (stack.empty()) return 0;
            if (stack.back() != same[c]) return 0;
            if (str[i - 1] == same[c]) {
                ans += tmp;
                tmp /= num[stack.back()];
                stack.pop_back();
            }
            else {
                tmp /= num[stack.back()];
                stack.pop_back();
            }
        }
    }
    // 올바르지 못한 괄호열
    if (!stack.empty()) return 0;
    return ans;
}

int main() {
    printf("%d", solve());
}