#include <iostream>
#include <vector>

using namespace std;

int arr[5] = { 5, 1, 2, 3, 4 };

vector<int> merge(vector<int>& l, vector<int>& r) {
    vector<int> v;
    int i = 0, j = 0;
    while (i < l.size() || j < r.size()) {
        if (i < l.size() && (j == r.size() || l[i] < r[j]))
            v.push_back(l[i++]);
        else
            v.push_back(r[j++]);
    }
    return v;
}

vector<int> mergeSort(int s, int e) {
    if (s == e) return {arr[s]};
    int mid = (s + e) / 2;
    vector<int> l = mergeSort(s, mid);
    vector<int> r = mergeSort(mid + 1, e);
    return merge(l, r);
}
