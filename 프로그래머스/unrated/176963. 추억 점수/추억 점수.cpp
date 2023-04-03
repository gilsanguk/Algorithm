#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> name2score;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    for (int i = 0; i < name.size(); i++) {
        name2score.insert({name[i], yearning[i]});
    }
    for (auto p:photo) {
        int tmp = 0;
        for (auto s:p) {
            tmp += name2score[s];
        }
        answer.push_back(tmp);
    }
    return answer;
}