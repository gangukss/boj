#include <iostream>
using namespace std;

#define M 1000001

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	bool PrimeArray[M];

	PrimeArray[0] = false;
	PrimeArray[1] = false;
	for (int i = 2; i <= M; i++)
	    PrimeArray[i] = true;
	for (int i = 2; i * i <= M; i++) {
		if (PrimeArray[i])
			for (int j = i * i; j <= M; j += i)
			    PrimeArray[j] = false;
	}

	int n;
	while (cin >> n) {
		if (!n)
			break ;
		int flag = 0;
		for (int i = 3; i < n; i += 2)
			if (PrimeArray[i] && PrimeArray[n - i]) {
				cout << n << " = " << i << " + " << n - i << "\n";
				flag = 1;
				break ;
			}
		if (!flag)
			cout << "Goldbach's conjecture is wrong.\n";
	}
}
