#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<string> user;
vector<string> ban;
vector<int> able[9];
bool visited[1 << 8];
int ans = 0;

bool possible(string A, string B, int a, int b){
    if (a == A.size()) return true;
    if (A[a] == B[b] || A[a] == '*') return possible(A, B, a+1, b+1);
    return false;
}

void backtrack(int cur, int used){
    if (cur == M){
        if (!visited[used]){
            ans++;
            visited[used] = true;
        } 
        return;
    }
    for (int i = 0; i < able[cur].size(); i++){
        if (used & (1 << able[cur][i])) continue;
        backtrack(cur + 1, used | (1 << able[cur][i]));
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    N = user_id.size();
    M = banned_id.size();
    for (int i = 0; i < M; i++) ban.push_back(banned_id[i]);
    for (int j = 0; j < N; j++) user.push_back(user_id[j]);
    
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            if (ban[i].size() != user[j].size()) continue;
            if (possible(ban[i], user[j], 0, 0)){
                able[i].push_back(j);
                }
        }
    }
    backtrack(0, 0); 
    int answer = ans;
    return answer;
}