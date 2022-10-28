#include <iostream>

using namespace std;

int main()
{
	int n, score = 0, j = 0;
	for (int i = 0; i < 10; i++) {
		cin >> n;
		if (score + n + j <= 100) {
			score += n;
		}
		else if (score + n - j > 100) {
			if ((100 - score) >= (score + n - 100))
				score += n;
			else
				j = 10000;
		}
		else
			j = 10000;
	}
	cout << score;
}