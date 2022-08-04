#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int d = b + c;
	if (d >= 60) {
		while (d >= 60) {
			d -= 60;
			a++;
		}
		if (a < 24)
			cout << a << " " << d;
		else
			cout << a - 24 << " " << d;
	}
	else
		cout << a << " " << d;
}