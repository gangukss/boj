#include <iostream>
#include <algorithm>
using namespace std;

int n;
int input[10000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> input[i];
	for (int i = n - 1; i >= 0; --i) {
		if (i == 0) {
			cout << -1;
			return 0;
		}
		if (input[i - 1] > input[i])
			continue ;
		for (int j = n - 1; j >= 0; --j) {
			if (input[i - 1] < input[j]) {
				int tmp = input[i - 1];
				input[i - 1] = input[j];
				input[j] = tmp;
				break ;
			} 
		}
		sort(input + i, input + n);
		break ;
	}
	for (int i = 0; i < n; ++i)
		cout << input[i] << " ";
}