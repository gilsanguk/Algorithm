#include <iostream>
using namespace std;
int main()
{
	int a,b;
	cin >> a >> b;

	if (b < 45)
	{
		if (a > 0)
			cout << a - 1 << " " << b + 15;
		else
			cout << a + 23 << " " << b + 15;
	}
	else 
			cout << a << " " << b - 45;
}