#include <iostream>
using namespace std;
int main()
{
	int n, i;
	int a = 0;
	cin >> n;
	for (i = 0; i <= n; i++) {
		a+=i;
	}
	cout << a;
}