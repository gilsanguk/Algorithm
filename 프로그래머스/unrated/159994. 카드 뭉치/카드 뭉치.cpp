#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int cards1Idx = 0, cards2Idx = 0;
    for (string word : goal) {
        if (cards1Idx < cards1.size() && cards1[cards1Idx] == word) {
            cards1Idx++;
            continue;
        }
        if (cards2Idx < cards2.size() && cards2[cards2Idx] == word) {
            cards2Idx++;
            continue;
        }
        return "No";
    }
    return "Yes";
}