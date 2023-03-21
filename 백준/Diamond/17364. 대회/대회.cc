#include <iostream>
#include <set>

using namespace std;

struct Contest {
	int s, e;
	bool operator<(const Contest& rhs) const {
		if (e == rhs.e) return s < rhs.s;
		return e < rhs.e;
	}
};
multiset<Contest> contests;
multiset<int> cur;
int N, K;

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		contests.insert({ s, e });
	}
	int ans = 0;
	int meEnd = 0;
	for (auto &it: contests) {
		if (it.s <= meEnd) continue;
		auto it2 = cur.lower_bound(it.s);
		if (it2 == cur.begin()) {
			if (cur.size() < K - 1) {
				cur.insert(it.e);
			}
			else {
				ans++;
				meEnd = it.e;
			}
		}
		else {
			it2--;
			cur.erase(it2);
			cur.insert(it.e);
		}
	}
	printf("%d", ans);
}