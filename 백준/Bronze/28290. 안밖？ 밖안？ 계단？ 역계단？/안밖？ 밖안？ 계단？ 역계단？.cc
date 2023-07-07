#include <iostream>

using namespace std;

char S[8];

string solve() {
    scanf("%s", S);
    string str(S);
    if (str == "fdsajkl;" || str == "jkl;fdsa") return "in-out";
    if (str == "asdf;lkj" || str == ";lkjasdf") return "out-in";
    if (str == "asdfjkl;") return "stairs";
    if (str == ";lkjfdsa") return "reverse";
    return "molu";
}

int main() {
    printf("%s", solve().c_str());
}