#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    int cnt = 1;
    if (s.length()==1 && s[0] == ' ') cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i != 0 && i != (s.length()-1) && s[i] == ' '){
            cnt++;
        }
    }
    cout << cnt;
}