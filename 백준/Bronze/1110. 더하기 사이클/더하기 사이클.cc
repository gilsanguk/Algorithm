#include <iostream>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, N;
	int count = 0;
	cin >> N;
	int M = N;
	do{
		A = (M % 10) * 10 + ((M / 10) + (M % 10)) % 10;

		count++;
		M = A;
	} while (A != N);

	cout << count;
}