#include <iostream>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, i, T;
	cin >> T;
	for (i = 0; i < T; i++) {
		cin >> a >> b;
		cout << a + b << "\n";
	}
}