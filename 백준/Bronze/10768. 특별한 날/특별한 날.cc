#include <iostream>

using namespace std;

int M, D;

string solve() {
    scanf("%d %d", &M, &D);
    if (M < 2 || (M == 2 && D < 18)) return "Before";
    if (M == 2 && D == 18) return "Special";
    return "After";
}

int main() {
    printf("%s", solve().c_str());
}