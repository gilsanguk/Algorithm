#include <iostream>

using namespace std;

int T;
char word[1001];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", word);
        string s(word);
        printf("%c%c\n", s[0], s[s.length()-1]);
    }
}