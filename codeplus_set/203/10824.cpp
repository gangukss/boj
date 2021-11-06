#include <iostream>
#include <string>
using namespace std;

string a, b, c, d;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c >> d;
	long long i = stoll(a + b);
	long long j = stoll(c + d);
	cout << i + j;
}
